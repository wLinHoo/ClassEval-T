package org.example;

import org.junit.jupiter.api.Test;
import java.util.Map;
import static org.junit.jupiter.api.Assertions.*;

public class URLHandlerTest {

    @Test
    public void testGetScheme1() {
        URLHandler urlhandler = new URLHandler("https://www.baidu.com/s?wd=aaa&rsv_spt=1#page");
        String temp = urlhandler.getScheme();
        assertEquals("https", temp);
    }

    @Test
    public void testGetScheme2() {
        URLHandler urlhandler = new URLHandler("https://www.bing.com/search?pglt=41&q=humaneval&cvid=4dc2da2bb4bc429eb498c85245ae5253&aqs=edge.0.0l7j69i61j69i60.10008j0j1&FORM=ANNTA1&PC=U531&mkt=zh-CN");
        String temp = urlhandler.getScheme();
        assertEquals("https", temp);
    }

    @Test
    public void testGetScheme3() {
        URLHandler urlhandler = new URLHandler("https://github.com/openai/human-eval");
        String temp = urlhandler.getScheme();
        assertEquals("https", temp);
    }

    @Test
    public void testGetScheme4() {
        URLHandler urlhandler = new URLHandler("aaa://github.com/openai/human-eval");
        String temp = urlhandler.getScheme();
        assertEquals("aaa", temp);
    }

    @Test
    public void testGetScheme5() {
        URLHandler urlhandler = new URLHandler("bbb://github.com/openai/human-eval");
        String temp = urlhandler.getScheme();
        assertEquals("bbb", temp);
    }

    @Test
    public void testGetScheme6() {
        URLHandler urlhandler = new URLHandler("abcdefg");
        String temp = urlhandler.getScheme();
        assertNull(temp);
    }

    @Test
    public void testGetHost1() {
        URLHandler urlhandler = new URLHandler("https://www.baidu.com/s?wd=aaa&rsv_spt=1#page");
        String temp = urlhandler.getHost();
        assertEquals("www.baidu.com", temp);
    }

    @Test
    public void testGetHost2() {
        URLHandler urlhandler = new URLHandler("https://www.bing.com/search?pglt=41&q=humaneval&cvid=4dc2da2bb4bc429eb498c85245ae5253&aqs=edge.0.0l7j69i61j69i60.10008j0j1&FORM=ANNTA1&PC=U531&mkt=zh-CN");
        String temp = urlhandler.getHost();
        assertEquals("www.bing.com", temp);
    }

    @Test
    public void testGetHost3() {
        URLHandler urlhandler = new URLHandler("https://github.com/openai/human-eval");
        String temp = urlhandler.getHost();
        assertEquals("github.com", temp);
    }

    @Test
    public void testGetHost4() {
        URLHandler urlhandler = new URLHandler("https://aaa.com/openai/human-eval");
        String temp = urlhandler.getHost();
        assertEquals("aaa.com", temp);
    }

    @Test
    public void testGetHost5() {
        URLHandler urlhandler = new URLHandler("https://bbb.com/openai/human-eval");
        String temp = urlhandler.getHost();
        assertEquals("bbb.com", temp);
    }

    @Test
    public void testGetHost6() {
        URLHandler urlhandler = new URLHandler("abcdefg");
        String temp = urlhandler.getHost();
        assertNull(temp);
    }

    @Test
    public void testGetHost7() {
        URLHandler urlhandler = new URLHandler("https://bbb.com");
        String temp = urlhandler.getHost();
        assertEquals("bbb.com", temp);
    }

    @Test
    public void testGetHost8() {
        URLHandler urlhandler = new URLHandler("https://bbb.com/");
        String temp = urlhandler.getHost();
        assertEquals("bbb.com", temp);
    }

    @Test
    public void testGetPath1() {
        URLHandler urlhandler = new URLHandler("https://www.baidu.com/s?wd=aaa&rsv_spt=1#page");
        String temp = urlhandler.getPath();
        assertEquals("/s?wd=aaa&rsv_spt=1#page", temp);
    }

    @Test
    public void testGetPath2() {
        URLHandler urlhandler = new URLHandler("https://www.bing.com/search?pglt=41&q=humaneval&cvid=4dc2da2bb4bc429eb498c85245ae5253&aqs=edge.0.0l7j69i61j69i60.10008j0j1&FORM=ANNTA1&PC=U531&mkt=zh-CN");
        String temp = urlhandler.getPath();
        assertEquals("/search?pglt=41&q=humaneval&cvid=4dc2da2bb4bc429eb498c85245ae5253&aqs=edge.0.0l7j69i61j69i60.10008j0j1&FORM=ANNTA1&PC=U531&mkt=zh-CN", temp);
    }

    @Test
    public void testGetPath3() {
        URLHandler urlhandler = new URLHandler("https://github.com/openai/human-eval");
        String temp = urlhandler.getPath();
        assertEquals("/openai/human-eval", temp);
    }

    @Test
    public void testGetPath4() {
        URLHandler urlhandler = new URLHandler("https://github.com/aaa/human-eval");
        String temp = urlhandler.getPath();
        assertEquals("/aaa/human-eval", temp);
    }

    @Test
    public void testGetPath5() {
        URLHandler urlhandler = new URLHandler("https://github.com/bbb/human-eval");
        String temp = urlhandler.getPath();
        assertEquals("/bbb/human-eval", temp);
    }

    @Test
    public void testGetPath6() {
        URLHandler urlhandler = new URLHandler("abcdefg");
        String temp = urlhandler.getPath();
        assertNull(temp);
    }

    @Test
    public void testGetQueryParams1() {
        URLHandler urlhandler = new URLHandler("https://www.baidu.com/s?wd=aaa&rsv_spt=1#page");
        Map<String, String> temp = urlhandler.getQueryParams();
        assertEquals(2, temp.size());
        assertEquals("aaa", temp.get("wd"));
        assertEquals("1", temp.get("rsv_spt"));
    }

    @Test
    public void testGetQueryParams2() {
        URLHandler urlhandler = new URLHandler("https://www.bing.com/search?pglt=41&q=humaneval&cvid=4dc2da2bb4bc429eb498c85245ae5253&aqs=edge.0.0l7j69i61j69i60.10008j0j1&FORM=ANNTA1&PC=U531#");
        Map<String, String> temp = urlhandler.getQueryParams();
        assertEquals(6, temp.size());
        assertEquals("41", temp.get("pglt"));
        assertEquals("humaneval", temp.get("q"));
        assertEquals("4dc2da2bb4bc429eb498c85245ae5253", temp.get("cvid"));
        assertEquals("edge.0.0l7j69i61j69i60.10008j0j1", temp.get("aqs"));
        assertEquals("ANNTA1", temp.get("FORM"));
        assertEquals("U531", temp.get("PC"));
    }

    @Test
    public void testGetQueryParams3() {
        URLHandler urlhandler = new URLHandler("https://github.com/openai/human-eval");
        Map<String, String> temp = urlhandler.getQueryParams();
        assertNull(temp);
    }

    @Test
    public void testGetQueryParams4() {
        URLHandler urlhandler = new URLHandler("https://www.baidu.com/s?wd=bbb&rsv_spt=1#page");
        Map<String, String> temp = urlhandler.getQueryParams();
        assertEquals(2, temp.size());
        assertEquals("bbb", temp.get("wd"));
        assertEquals("1", temp.get("rsv_spt"));
    }

    @Test
    public void testGetQueryParams5() {
        URLHandler urlhandler = new URLHandler("https://www.baidu.com/s?wd=ccc&rsv_spt=1#page");
        Map<String, String> temp = urlhandler.getQueryParams();
        assertEquals(2, temp.size());
        assertEquals("ccc", temp.get("wd"));
        assertEquals("1", temp.get("rsv_spt"));
    }

    @Test
    public void testGetQueryParams6() {
        URLHandler urlhandler = new URLHandler("https://www.baidu.com/s?&#page");
        Map<String, String> temp = urlhandler.getQueryParams();
        assertEquals(0, temp.size());
    }

    @Test
    public void testGetFragment1() {
        URLHandler urlhandler = new URLHandler("https://www.baidu.com/s?wd=aaa&rsv_spt=1#page");
        String temp = urlhandler.getFragment();
        assertEquals("page", temp);
    }

    @Test
    public void testGetFragment2() {
        URLHandler urlhandler = new URLHandler("https://www.bing.com/search?pglt=41&q=humaneval&cvid=4dc2da2bb4bc429eb498c85245ae5253&aqs=edge.0.0l7j69i61j69i60.10008j0j1&FORM=ANNTA1&PC=U531&mkt=zh-CN");
        String temp = urlhandler.getFragment();
        assertNull(temp);
    }

    @Test
    public void testGetFragment3() {
        URLHandler urlhandler = new URLHandler("https://www.baidu.com/s?wd=aaa&rsv_spt=1#aaa");
        String temp = urlhandler.getFragment();
        assertEquals("aaa", temp);
    }

    @Test
    public void testGetFragment4() {
        URLHandler urlhandler = new URLHandler("https://www.baidu.com/s?wd=aaa&rsv_spt=1#bbb");
        String temp = urlhandler.getFragment();
        assertEquals("bbb", temp);
    }

    @Test
    public void testGetFragment5() {
        URLHandler urlhandler = new URLHandler("https://www.baidu.com/s?wd=aaa&rsv_spt=1#ccc");
        String temp = urlhandler.getFragment();
        assertEquals("ccc", temp);
    }

    @Test
    public void testURLHandler() {
        URLHandler urlhandler = new URLHandler("https://www.baidu.com/s?wd=aaa&rsv_spt=1#page");
        String temp = urlhandler.getScheme();
        assertEquals("https", temp);
        temp = urlhandler.getHost();
        assertEquals("www.baidu.com", temp);
        temp = urlhandler.getPath();
        assertEquals("/s?wd=aaa&rsv_spt=1#page", temp);
        Map<String, String> tempMap = urlhandler.getQueryParams();
        assertEquals(2, tempMap.size());
        assertEquals("aaa", tempMap.get("wd"));
        assertEquals("1", tempMap.get("rsv_spt"));
        temp = urlhandler.getFragment();
        assertEquals("page", temp);
    }
}