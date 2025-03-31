import java.util.ArrayList;
import java.util.List;

public class AutomaticGuitarSimulator {
    private String playText;

    public AutomaticGuitarSimulator(String text) {
        this.playText = text;
    }

    public String display(String key, String value) {
        return "Normal Guitar Playing -- Chord: " + key + ", Play Tune: " + value;
    }

    public List<Play> interpret(boolean display) {
        if (playText.isEmpty()) {
            return new ArrayList<>();
        } else {
            List<Play> playList = new ArrayList<>();
            String[] playSegs = playText.split(" ");
            for (String playSeg : playSegs) {
                int pos = 0;
                for (char ele : playSeg.toCharArray()) {
                    if (Character.isLetter(ele)) {
                        pos += 1;
                        continue;
                    }
                    break;
                }
                String playChord = playSeg.substring(0, pos);
                String playValue = playSeg.substring(pos);
                Play play = new Play(playChord, playValue);
                playList.add(play);
                if (display) {
                    System.out.println(playChord + " " + playValue);
                }
            }
            return playList;
        }
    }

    private static class Play {
        private String chord;
        private String tune;

        public Play(String chord, String tune) {
            this.chord = chord;
            this.tune = tune;
        }

        public String getChord() {
            return chord;
        }

        public String getTune() {
            return tune;
        }
    }
}