import java.net.URLDecoder;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

public class UrlPath {
    private List<String> segments;
    private boolean withEndTag;

    public UrlPath() {
        this.segments = new ArrayList<>();
        this.withEndTag = false;
    }

    public void add(String segment) {
        this.segments.add(fixPath(segment));
    }

    public void parse(String path, String charset) {
        if (path != null && !path.isEmpty()) {
            if (path.endsWith("/")) {
                this.withEndTag = true;
            }

            path = fixPath(path);
            if (path != null && !path.isEmpty()) {
                String[] split = path.split("/");
                for (String seg : split) {
                    try {
                        String decodedSeg = URLDecoder.decode(seg, charset);
                        this.segments.add(decodedSeg);
                    } catch (Exception e) {
                        // handle exception
                    }
                }
            }
        }
    }

    private String fixPath(String path) {
        if (path == null || path.isEmpty()) {
            return "";
        }

        String segmentStr = path.strip().replaceAll("^/", "").replaceAll("/$", "");
        return segmentStr;
    }
}