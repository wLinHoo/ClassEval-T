import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import java.io.File;
import java.io.IOException;

public class ImageProcessor {
    private BufferedImage image;

    public ImageProcessor() {
        this.image = null;
    }

    public void loadImage(String imagePath) throws IOException {
        this.image = ImageIO.read(new File(imagePath));
    }

    public void setImage(BufferedImage image) {
        this.image = image;
    }

    public void resizeImage(int width, int height) throws IOException {
        if (image != null) {
            BufferedImage newImage = new BufferedImage(width, height, image.getType());
            newImage.getGraphics().drawImage(image, 0, 0, width, height, null);
            this.image = newImage;
        }
    }

    public void rotateImage(int degrees) {
        if (image != null) {
            try {
                BufferedImage rotatedImage = new BufferedImage(image.getWidth(), image.getHeight(), image.getType());
                for (int x = 0; x < image.getWidth(); x++) {
                    for (int y = 0; y < image.getHeight(); y++) {
                        int newX = (int) (x * Math.cos(Math.toRadians(degrees))) - (int) (y * Math.sin(Math.toRadians(degrees)));
                        int newY = (int) (x * Math.sin(Math.toRadians(degrees))) + (int) (y * Math.cos(Math.toRadians(degrees)));
                        if (newX >= 0 && newX < image.getWidth() && newY >= 0 && newY < image.getHeight()) {
                            rotatedImage.setRGB(newX, newY, image.getRGB(x, y));
                        }
                    }
                }
                this.image = rotatedImage;
            } catch (Exception e) {
                System.out.println("Error rotating image: " + e.getMessage());
            }
        }
    }

    public void adjustBrightness(float factor) {
        if (image != null) {
            for (int y = 0; y < image.getHeight(); y++) {
                for (int x = 0; x < image.getWidth(); x++) {
                    int pixel = image.getRGB(x, y);
                    int red = (int) (((pixel >> 16) & 0xff) * factor);
                    int green = (int) (((pixel >> 8) & 0xff) * factor);
                    int blue = (int) ((pixel & 0xff) * factor);
                    red = Math.min(Math.max(red, 0), 255);
                    green = Math.min(Math.max(green, 0), 255);
                    blue = Math.min(Math.max(blue, 0), 255);
                    pixel = (red << 16) | (green << 8) | blue;
                    image.setRGB(x, y, pixel);
                }
            }
        }
    }

    public void saveImage(String savePath) {
        if (this.image != null) {
            try {
                File file = new File(savePath);
                ImageIO.write(this.image, "jpg", file);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}