package org.example;

import org.junit.jupiter.api.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

public class AutomaticGuitarSimulatorTest {

    @Test
    public void testInterpret1() {
        AutomaticGuitarSimulator context = new AutomaticGuitarSimulator("C53231323");
        List<AutomaticGuitarSimulator.ChordTune> playList = context.interpret(false);
        assertEquals(1, playList.size());
        assertEquals(new AutomaticGuitarSimulator.ChordTune("C", "53231323"), playList.get(0));
    }

    @Test
    public void testInterpret2() {
        AutomaticGuitarSimulator context = new AutomaticGuitarSimulator("F43231323");
        List<AutomaticGuitarSimulator.ChordTune> playList = context.interpret(false);
        assertEquals(1, playList.size());
        assertEquals(new AutomaticGuitarSimulator.ChordTune("F", "43231323"), playList.get(0));
    }

    @Test
    public void testInterpret3() {
        AutomaticGuitarSimulator context = new AutomaticGuitarSimulator("Em43231323");
        List<AutomaticGuitarSimulator.ChordTune> playList = context.interpret(false);
        assertEquals(1, playList.size());
        assertEquals(new AutomaticGuitarSimulator.ChordTune("Em", "43231323"), playList.get(0));
    }

    @Test
    public void testInterpret4() {
        AutomaticGuitarSimulator context = new AutomaticGuitarSimulator("G63231323");
        List<AutomaticGuitarSimulator.ChordTune> playList = context.interpret(false);
        assertEquals(1, playList.size());
        assertEquals(new AutomaticGuitarSimulator.ChordTune("G", "63231323"), playList.get(0));
    }

    @Test
    public void testInterpret5() {
        AutomaticGuitarSimulator context = new AutomaticGuitarSimulator("F43231323 G63231323");
        List<AutomaticGuitarSimulator.ChordTune> playList = context.interpret(false);
        assertEquals(2, playList.size());
        assertEquals(new AutomaticGuitarSimulator.ChordTune("F", "43231323"), playList.get(0));
        assertEquals(new AutomaticGuitarSimulator.ChordTune("G", "63231323"), playList.get(1));
    }

    @Test
    public void testInterpret6() {
        AutomaticGuitarSimulator context = new AutomaticGuitarSimulator(" ");
        List<AutomaticGuitarSimulator.ChordTune> playList = context.interpret(false);
        assertNull(playList);
    }

    @Test
    public void testInterpret7() {
        AutomaticGuitarSimulator context = new AutomaticGuitarSimulator("ABC43231323 DEF63231323");
        List<AutomaticGuitarSimulator.ChordTune> playList = context.interpret(false);
        assertEquals(2, playList.size());
        assertEquals(new AutomaticGuitarSimulator.ChordTune("ABC", "43231323"), playList.get(0));
        assertEquals(new AutomaticGuitarSimulator.ChordTune("DEF", "63231323"), playList.get(1));
    }

    @Test
    public void testInterpret8() {
        AutomaticGuitarSimulator context = new AutomaticGuitarSimulator("C53231323");
        List<AutomaticGuitarSimulator.ChordTune> playList = context.interpret(true);
        assertEquals(1, playList.size());
        assertEquals(new AutomaticGuitarSimulator.ChordTune("C", "53231323"), playList.get(0));
    }

    @Test
    public void testInterpret9() {
        AutomaticGuitarSimulator context = new AutomaticGuitarSimulator("");
        List<AutomaticGuitarSimulator.ChordTune> playList = context.interpret(false);
        assertNull(playList);
    }

    @Test
    public void testDisplay1() {
        AutomaticGuitarSimulator context = new AutomaticGuitarSimulator("C53231323 Em43231323");
        List<AutomaticGuitarSimulator.ChordTune> playList = context.interpret(false);
        String str = context.display(playList.get(0).getChord(), playList.get(0).getTune());
        assertEquals("Normal Guitar Playing -- Chord: C, Play Tune: 53231323", str);
    }

    @Test
    public void testDisplay2() {
        AutomaticGuitarSimulator context = new AutomaticGuitarSimulator("C53231323 Em43231323");
        List<AutomaticGuitarSimulator.ChordTune> playList = context.interpret(false);
        String str = context.display(playList.get(1).getChord(), playList.get(1).getTune());
        assertEquals("Normal Guitar Playing -- Chord: Em, Play Tune: 43231323", str);
    }

    @Test
    public void testDisplay3() {
        AutomaticGuitarSimulator context = new AutomaticGuitarSimulator("F43231323 G63231323");
        List<AutomaticGuitarSimulator.ChordTune> playList = context.interpret(false);
        String str = context.display(playList.get(0).getChord(), playList.get(0).getTune());
        assertEquals("Normal Guitar Playing -- Chord: F, Play Tune: 43231323", str);
    }

    @Test
    public void testDisplay4() {
        AutomaticGuitarSimulator context = new AutomaticGuitarSimulator("F43231323 G63231323");
        List<AutomaticGuitarSimulator.ChordTune> playList = context.interpret(false);
        String str = context.display(playList.get(1).getChord(), playList.get(1).getTune());
        assertEquals("Normal Guitar Playing -- Chord: G, Play Tune: 63231323", str);
    }

    @Test
    public void testDisplay5() {
        AutomaticGuitarSimulator context = new AutomaticGuitarSimulator("");
        String str = context.display("", "");
        assertEquals("Normal Guitar Playing -- Chord: , Play Tune: ", str);
    }
}