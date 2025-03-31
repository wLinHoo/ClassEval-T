package org.example;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

import java.util.HashMap;
import java.util.Map;

public class ServerTest {

    private Server server;

    @BeforeEach
    public void setUp() {
        server = new Server();
    }

    @Test
    public void testAddWhiteList1() {
        server.addWhiteList(88);
        assertEquals(server.addWhiteList(88), null);
    }

    @Test
    public void testAddWhiteList2() {
        server.addWhiteList(88);
        assertEquals(server.addWhiteList(88), null);
    }

    @Test
    public void testAddWhiteList3() {
        server.addWhiteList(88);
        server.addWhiteList(11);
        assertEquals(server.addWhiteList(11), null);
    }

    @Test
    public void testAddWhiteList4() {
        server.addWhiteList(11);
        assertEquals(server.addWhiteList(11), null);
    }

    @Test
    public void testAddWhiteList5() {
        server.addWhiteList(88);
        server.addWhiteList(11);
        server.addWhiteList(22);
        assertEquals(server.addWhiteList(22), null);
    }

    @Test
    public void testDelWhiteList1() {
        server.addWhiteList(88);
        server.delWhiteList(88);
        assertEquals(server.delWhiteList(88), null);
    }

    @Test
    public void testDelWhiteList2() {
        assertEquals(server.delWhiteList(88), null);
    }

    @Test
    public void testDelWhiteList3() {
        assertEquals(server.delWhiteList(11), null);
    }

    @Test
    public void testDelWhiteList4() {
        assertEquals(server.delWhiteList(22), null);
    }

    @Test
    public void testDelWhiteList5() {
        server.addWhiteList(11);
        assertEquals(server.delWhiteList(22), null);
    }

    @Test
    public void testRecv1() {
        server.addWhiteList(88);
        Map<String, Object> info = new HashMap<>();
        info.put("addr", 88);
        info.put("content", "abc");
        server.recv(info);
        assertEquals(server.show("receive"), info);
    }

    @Test
    public void testRecv2() {
        server.addWhiteList(88);
        Map<String, Object> info = new HashMap<>();
        info.put("addr", 66);
        info.put("content", "abc");
        assertEquals(server.recv(info), false);
        assertEquals(server.show("receive"), new HashMap<>());
    }

    @Test
    public void testRecv3() {
        assertEquals(server.recv(new HashMap<>()), -1);
        assertEquals(server.show("receive"), new HashMap<>());
    }

    @Test
    public void testRecv4() {
        Map<String, Object> info = new HashMap<>();
        info.put("addr", 88);
        assertEquals(server.recv(info), -1);
        assertEquals(server.show("receive"), new HashMap<>());
    }

    @Test
    public void testRecv5() {
        Map<String, Object> info = new HashMap<>();
        info.put("content", "abc");
        assertEquals(server.recv(info), -1);
        assertEquals(server.show("receive"), new HashMap<>());
    }

    @Test
    public void testSend1() {
        Map<String, Object> info = new HashMap<>();
        info.put("addr", 88);
        info.put("content", "abc");
        server.send(info);
        assertEquals(server.show("send"), info);
    }

    @Test
    public void testSend2() {
        Map<String, Object> info = new HashMap<>();
        info.put("addr", 88);
        assertEquals(server.send(info), "info structure is not correct");
    }

    @Test
    public void testSend3() {
        Map<String, Object> info = new HashMap<>();
        info.put("content", "abc");
        assertEquals(server.send(info), "info structure is not correct");
    }

    @Test
    public void testSend4() {
        assertEquals(server.send(new HashMap<>()), "info structure is not correct");
    }

    @Test
    public void testSend5() {
        Map<String, Object> info = new HashMap<>();
        info.put("addr", 66);
        info.put("content", "abc");
        server.send(info);
        assertEquals(server.show("send"), info);
    }

    @Test
    public void testShow1() {
        server.addWhiteList(66);
        Map<String, Object> sendInfo = new HashMap<>();
        sendInfo.put("addr", 88);
        sendInfo.put("content", "abc");
        server.send(sendInfo);
        Map<String, Object> recvInfo = new HashMap<>();
        recvInfo.put("addr", 66);
        recvInfo.put("content", "ABC");
        server.recv(recvInfo);
        assertEquals(server.show("send"), sendInfo);
    }

    @Test
    public void testShow2() {
        server.addWhiteList(66);
        Map<String, Object> sendInfo = new HashMap<>();
        sendInfo.put("addr", 88);
        sendInfo.put("content", "abc");
        server.send(sendInfo);
        Map<String, Object> recvInfo = new HashMap<>();
        recvInfo.put("addr", 66);
        recvInfo.put("content", "ABC");
        server.recv(recvInfo);
        assertEquals(server.show("receive"), recvInfo);
    }

    @Test
    public void testShow3() {
        server.addWhiteList(66);
        Map<String, Object> sendInfo = new HashMap<>();
        sendInfo.put("addr", 88);
        sendInfo.put("content", "abc");
        server.send(sendInfo);
        Map<String, Object> recvInfo = new HashMap<>();
        recvInfo.put("addr", 66);
        recvInfo.put("content", "ABC");
        server.recv(recvInfo);
        assertEquals(server.show("abcdefg"), null);
    }

    @Test
    public void testShow4() {
        server.addWhiteList(66);
        Map<String, Object> sendInfo = new HashMap<>();
        sendInfo.put("addr", 11);
        sendInfo.put("content", "abc");
        server.send(sendInfo);
        Map<String, Object> recvInfo = new HashMap<>();
        recvInfo.put("addr", 66);
        recvInfo.put("content", "ABC");
        server.recv(recvInfo);
        assertEquals(server.show("send"), sendInfo);
    }

    @Test
    public void testShow5() {
        server.addWhiteList(66);
        Map<String, Object> sendInfo = new HashMap<>();
        sendInfo.put("addr", 22);
        sendInfo.put("content", "abc");
        server.send(sendInfo);
        Map<String, Object> recvInfo = new HashMap<>();
        recvInfo.put("addr", 66);
        recvInfo.put("content", "ABC");
        server.recv(recvInfo);
        assertEquals(server.show("send"), sendInfo);
    }

    @Test
    public void testServer() {
        server.addWhiteList(88);
        assertEquals(server.addWhiteList(88), null);
        server.delWhiteList(88);
        assertEquals(server.delWhiteList(88), null);
        server.addWhiteList(88);
        Map<String, Object> recvInfo = new HashMap<>();
        recvInfo.put("addr", 88);
        recvInfo.put("content", "abc");
        server.recv(recvInfo);
        assertEquals(server.show("receive"), recvInfo);
        Map<String, Object> sendInfo = new HashMap<>();
        sendInfo.put("addr", 66);
        sendInfo.put("content", "ABC");
        server.send(sendInfo);
        assertEquals(server.show("send"), sendInfo);
        server.recv(recvInfo);
        assertEquals(server.show("receive"), recvInfo);
    }
}