package org.example;

import java.util.ArrayList;
import java.util.List;

public class AutomaticGuitarSimulator {
    private String playText;

    public AutomaticGuitarSimulator(String text) {
        this.playText = text;
    }

    public List<ChordTune> interpret(boolean display) {
        if (playText == null || playText.trim().isEmpty()) {
            return null;
        }

        List<ChordTune> playList = new ArrayList<>();
        String[] playSegs = playText.split(" ");
        for (String playSeg : playSegs) {
            if (playSeg.trim().isEmpty()) {
                continue;
            }
            int pos = 0;
            for (char ele : playSeg.toCharArray()) {
                if (Character.isLetter(ele)) {
                    pos++;
                    continue;
                }
                break;
            }
            String playChord = playSeg.substring(0, pos);
            String playValue = playSeg.substring(pos);
            playList.add(new ChordTune(playChord, playValue));
            if (display) {
                display(playChord, playValue);
            }
        }
        return playList;
    }

    public String display(String key, String value) {
        return String.format("Normal Guitar Playing -- Chord: %s, Play Tune: %s", key, value);
    }

    public static class ChordTune {
        private String chord;
        private String tune;

        public ChordTune(String chord, String tune) {
            this.chord = chord;
            this.tune = tune;
        }

        public String getChord() {
            return chord;
        }

        public String getTune() {
            return tune;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            ChordTune that = (ChordTune) obj;
            return chord.equals(that.chord) && tune.equals(that.tune);
        }

        @Override
        public int hashCode() {
            int result = chord.hashCode();
            result = 31 * result + tune.hashCode();
            return result;
        }
    }
}