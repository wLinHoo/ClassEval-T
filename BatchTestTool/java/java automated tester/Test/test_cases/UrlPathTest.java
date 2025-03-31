package test_cases;
import to_be_tested.UrlPath;

import org.junit.jupiter.api.Test;
import java.util.List;
import static org.junit.jupiter.api.Assertions.*;

public class UrlPathTest {

    @Test
    public void testAdd1() {
        UrlPath urlPath = new UrlPath();
        urlPath.add("foo");
        urlPath.add("bar");
        assertEquals(List.of("foo", "bar"), urlPath.getSegments());
    }

    @Test
    public void testAdd2() {
        UrlPath urlPath = new UrlPath();
        urlPath.add("aaa");
        urlPath.add("bbb");
        assertEquals(List.of("aaa", "bbb"), urlPath.getSegments());
    }

    @Test
    public void testAdd3() {
        UrlPath urlPath = new UrlPath();
        urlPath.add("123");
        assertEquals(List.of("123"), urlPath.getSegments());
    }

    @Test
    public void testAdd4() {
        UrlPath urlPath = new UrlPath();
        urlPath.add("ddd");
        assertEquals(List.of("ddd"), urlPath.getSegments());
    }

    @Test
    public void testAdd5() {
        UrlPath urlPath = new UrlPath();
        urlPath.add("eee");
        assertEquals(List.of("eee"), urlPath.getSegments());
    }

    @Test
    public void testParse1() {
        UrlPath urlPath = new UrlPath();
        urlPath.parse("/foo/bar/", "utf-8");
        assertEquals(List.of("foo", "bar"), urlPath.getSegments());
        assertTrue(urlPath.isWithEndTag());
    }

    @Test
    public void testParse2() {
        UrlPath urlPath = new UrlPath();
        urlPath.parse("aaa/bbb", "utf-8");
        assertEquals(List.of("aaa", "bbb"), urlPath.getSegments());
        assertFalse(urlPath.isWithEndTag());
    }

    @Test
    public void testParse3() {
        UrlPath urlPath = new UrlPath();
        urlPath.parse("/123/456/", "utf-8");
        assertEquals(List.of("123", "456"), urlPath.getSegments());
        assertTrue(urlPath.isWithEndTag());
    }

    @Test
    public void testParse4() {
        UrlPath urlPath = new UrlPath();
        urlPath.parse("/123/456/789", "utf-8");
        assertEquals(List.of("123", "456", "789"), urlPath.getSegments());
        assertFalse(urlPath.isWithEndTag());
    }

    @Test
    public void testParse5() {
        UrlPath urlPath = new UrlPath();
        urlPath.parse("/foo/bar", "utf-8");
        assertEquals(List.of("foo", "bar"), urlPath.getSegments());
        assertFalse(urlPath.isWithEndTag());
    }

    @Test
    public void testParse6() {
        UrlPath urlPath = new UrlPath();
        urlPath.parse("", "utf-8");
        assertEquals(List.of(), urlPath.getSegments());
        assertFalse(urlPath.isWithEndTag());
    }

    @Test
    public void testParse7() {
        UrlPath urlPath = new UrlPath();
        urlPath.parse("//", "utf-8");
        assertEquals(List.of(), urlPath.getSegments());
        assertTrue(urlPath.isWithEndTag());
    }

    @Test
    public void testFixPath1() {
        String fixedPath = UrlPath.fixPath("/foo/bar/");
        assertEquals("foo/bar", fixedPath);
    }

    @Test
    public void testFixPath2() {
        String fixedPath = UrlPath.fixPath("/aaa/bbb/");
        assertEquals("aaa/bbb", fixedPath);
    }

    @Test
    public void testFixPath3() {
        String fixedPath = UrlPath.fixPath("/a/b/");
        assertEquals("a/b", fixedPath);
    }

    @Test
    public void testFixPath4() {
        String fixedPath = UrlPath.fixPath("/111/222/");
        assertEquals("111/222", fixedPath);
    }

    @Test
    public void testFixPath5() {
        String fixedPath = UrlPath.fixPath("/a/");
        assertEquals("a", fixedPath);
    }

    @Test
    public void testFixPath6() {
        String fixedPath = UrlPath.fixPath("");
        assertEquals("", fixedPath);
    }

    @Test
    public void testUrlPath() {
        UrlPath urlPath = new UrlPath();
        urlPath.add("foo");
        urlPath.add("bar");
        assertEquals(List.of("foo", "bar"), urlPath.getSegments());

        urlPath = new UrlPath();
        urlPath.parse("/foo/bar/", "utf-8");
        assertEquals(List.of("foo", "bar"), urlPath.getSegments());
        assertTrue(urlPath.isWithEndTag());

        String fixedPath = UrlPath.fixPath("/foo/bar/");
        assertEquals("foo/bar", fixedPath);
    }
}