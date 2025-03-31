package org.example;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class PageUtilTest {

    private List<Integer> data;
    private int pageSize;
    private PageUtil pageUtil;

    @BeforeEach
    public void setUp() {
        data = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        pageSize = 3;
        pageUtil = new PageUtil(data, pageSize);
    }

    @Test
    public void testGetPage1() {
        int pageNumber = 1;
        List<Integer> expectedPage = Arrays.asList(1, 2, 3);
        List<Integer> actualPage = pageUtil.getPage(pageNumber);
        assertEquals(expectedPage, actualPage);
    }

    @Test
    public void testGetPage2() {
        int pageNumber = 2;
        List<Integer> expectedPage = Arrays.asList(4, 5, 6);
        List<Integer> actualPage = pageUtil.getPage(pageNumber);
        assertEquals(expectedPage, actualPage);
    }

    @Test
    public void testGetPage3() {
        int pageNumber = 3;
        List<Integer> expectedPage = Arrays.asList(7, 8, 9);
        List<Integer> actualPage = pageUtil.getPage(pageNumber);
        assertEquals(expectedPage, actualPage);
    }

    @Test
    public void testGetPage4() {
        int pageNumber = 4;
        List<Integer> expectedPage = Arrays.asList(10);
        List<Integer> actualPage = pageUtil.getPage(pageNumber);
        assertEquals(expectedPage, actualPage);
    }

    @Test
    public void testGetPage5() {
        int invalidPageNumber = 0;
        List<Integer> emptyPage = Arrays.asList();
        List<Integer> actualPage = pageUtil.getPage(invalidPageNumber);
        assertEquals(emptyPage, actualPage);
    }

    @Test
    public void testGetPageInfo1() {
        int pageNumber = 2;
        PageUtil.PageInfo expectedInfo = new PageUtil.PageInfo(
                pageNumber,
                pageSize,
                4,
                10,
                true,
                true,
                Arrays.asList(4, 5, 6)
        );
        PageUtil.PageInfo actualInfo = pageUtil.getPageInfo(pageNumber);
        assertEquals(expectedInfo, actualInfo);
    }

    @Test
    public void testGetPageInfo2() {
        int pageNumber = 1;
        PageUtil.PageInfo expectedInfo = new PageUtil.PageInfo(
                pageNumber,
                pageSize,
                4,
                10,
                false,
                true,
                Arrays.asList(1, 2, 3)
        );
        PageUtil.PageInfo actualInfo = pageUtil.getPageInfo(pageNumber);
        assertEquals(expectedInfo, actualInfo);
    }

    @Test
    public void testGetPageInfo3() {
        int pageNumber = 3;
        PageUtil.PageInfo expectedInfo = new PageUtil.PageInfo(
                pageNumber,
                pageSize,
                4,
                10,
                true,
                true,
                Arrays.asList(7, 8, 9)
        );
        PageUtil.PageInfo actualInfo = pageUtil.getPageInfo(pageNumber);
        assertEquals(expectedInfo, actualInfo);
    }

    @Test
    public void testGetPageInfo4() {
        int pageNumber = 4;
        PageUtil.PageInfo expectedInfo = new PageUtil.PageInfo(
                pageNumber,
                pageSize,
                4,
                10,
                true,
                false,
                Arrays.asList(10)
        );
        PageUtil.PageInfo actualInfo = pageUtil.getPageInfo(pageNumber);
        assertEquals(expectedInfo, actualInfo);
    }

    @Test
    public void testGetPageInfo5() {
        int invalidPageNumber = 5;
        PageUtil.PageInfo emptyInfo = new PageUtil.PageInfo(
                0,
                pageSize,
                4,
                10,
                false,
                false,
                Arrays.asList()
        );
        PageUtil.PageInfo actualInfo = pageUtil.getPageInfo(invalidPageNumber);
        assertEquals(emptyInfo, actualInfo);
    }

    @Test
    public void testSearch1() {
        String keyword = "1";
        PageUtil.SearchResult expectedResults = new PageUtil.SearchResult(
                "1", 2, 1, Arrays.asList(1, 10)
        );
        PageUtil.SearchResult actualResults = pageUtil.search(keyword);
        assertEquals(expectedResults, actualResults);
    }

    @Test
    public void testSearch2() {
        String keyword = "2";
        PageUtil.SearchResult expectedResults = new PageUtil.SearchResult(
                "2", 1, 1, Arrays.asList(2)
        );
        PageUtil.SearchResult actualResults = pageUtil.search(keyword);
        assertEquals(expectedResults, actualResults);
    }

    @Test
    public void testSearch3() {
        String keyword = "3";
        PageUtil.SearchResult expectedResults = new PageUtil.SearchResult(
                "3", 1, 1, Arrays.asList(3)
        );
        PageUtil.SearchResult actualResults = pageUtil.search(keyword);
        assertEquals(expectedResults, actualResults);
    }

    @Test
    public void testSearch4() {
        String keyword = "4";
        PageUtil.SearchResult expectedResults = new PageUtil.SearchResult(
                "4", 1, 1, Arrays.asList(4)
        );
        PageUtil.SearchResult actualResults = pageUtil.search(keyword);
        assertEquals(expectedResults, actualResults);
    }

    @Test
    public void testSearch5() {
        String keyword = "11";
        PageUtil.SearchResult expectedResults = new PageUtil.SearchResult(
                "11", 0, 0, Arrays.asList()
        );
        PageUtil.SearchResult actualResults = pageUtil.search(keyword);
        assertEquals(expectedResults, actualResults);
    }

    @Test
    public void testPageUtil() {
        int pageNumber = 1;
        List<Integer> expectedPage = Arrays.asList(1, 2, 3);
        List<Integer> actualPage = pageUtil.getPage(pageNumber);
        assertEquals(expectedPage, actualPage);

        pageNumber = 2;
        PageUtil.PageInfo expectedInfo = new PageUtil.PageInfo(
                pageNumber,
                pageSize,
                4,
                10,
                true,
                true,
                Arrays.asList(4, 5, 6)
        );
        PageUtil.PageInfo actualInfo = pageUtil.getPageInfo(pageNumber);
        assertEquals(expectedInfo, actualInfo);

        String keyword = "4";
        PageUtil.SearchResult expectedResults = new PageUtil.SearchResult(
                "4", 1, 1, Arrays.asList(4)
        );
        PageUtil.SearchResult actualResults = pageUtil.search(keyword);
        assertEquals(expectedResults, actualResults);
    }
}
