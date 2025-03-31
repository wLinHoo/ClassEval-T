package org.example;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class PageUtil {
    private List<Integer> data;
    private int pageSize;
    private int totalItems;
    private int totalPages;

    public PageUtil(List<Integer> data, int pageSize) {
        this.data = data;
        this.pageSize = pageSize;
        this.totalItems = data.size();
        this.totalPages = (int) Math.ceil((double) totalItems / pageSize);
    }

    public List<Integer> getPage(int pageNumber) {
        if (pageNumber < 1 || pageNumber > totalPages) {
            return new ArrayList<>();
        }

        int startIndex = (pageNumber - 1) * pageSize;
        int endIndex = Math.min(startIndex + pageSize, totalItems);
        return data.subList(startIndex, endIndex);
    }

    public PageInfo getPageInfo(int pageNumber) {
        if (pageNumber < 1 || pageNumber > totalPages) {
            return new PageInfo(0, pageSize, totalPages, totalItems, false, false, new ArrayList<>());
        }

        int startIndex = (pageNumber - 1) * pageSize;
        int endIndex = Math.min(startIndex + pageSize, totalItems);
        List<Integer> pageData = data.subList(startIndex, endIndex);

        boolean hasPrevious = pageNumber > 1;
        boolean hasNext = pageNumber < totalPages;

        return new PageInfo(
                pageNumber,
                pageSize,
                totalPages,
                totalItems,
                hasPrevious,
                hasNext,
                pageData
        );
    }

    public SearchResult search(String keyword) {
        List<Integer> results = data.stream()
                .filter(item -> item.toString().contains(keyword))
                .collect(Collectors.toList());

        int numResults = results.size();
        int numPages = (int) Math.ceil((double) numResults / pageSize);

        return new SearchResult(
                keyword,
                numResults,
                numPages,
                results
        );
    }

    public static class PageInfo {
        public int currentPage;
        public int perPage;
        public int totalPages;
        public int totalItems;
        public boolean hasPrevious;
        public boolean hasNext;
        public List<Integer> data;

        public PageInfo(int currentPage, int perPage, int totalPages, int totalItems, boolean hasPrevious, boolean hasNext, List<Integer> data) {
            this.currentPage = currentPage;
            this.perPage = perPage;
            this.totalPages = totalPages;
            this.totalItems = totalItems;
            this.hasPrevious = hasPrevious;
            this.hasNext = hasNext;
            this.data = data != null ? new ArrayList<>(data) : new ArrayList<>();
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            PageInfo pageInfo = (PageInfo) obj;
            return currentPage == pageInfo.currentPage &&
                    perPage == pageInfo.perPage &&
                    totalPages == pageInfo.totalPages &&
                    totalItems == pageInfo.totalItems &&
                    hasPrevious == pageInfo.hasPrevious &&
                    hasNext == pageInfo.hasNext &&
                    data.equals(pageInfo.data);
        }

        @Override
        public int hashCode() {
            int result = currentPage;
            result = 31 * result + perPage;
            result = 31 * result + totalPages;
            result = 31 * result + totalItems;
            result = 31 * result + (hasPrevious ? 1 : 0);
            result = 31 * result + (hasNext ? 1 : 0);
            result = 31 * result + data.hashCode();
            return result;
        }
    }

    public static class SearchResult {
        public String keyword;
        public int totalResults;
        public int totalPages;
        public List<Integer> results;

        public SearchResult(String keyword, int totalResults, int totalPages, List<Integer> results) {
            this.keyword = keyword;
            this.totalResults = totalResults;
            this.totalPages = totalPages;
            this.results = results != null ? new ArrayList<>(results) : new ArrayList<>();
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            SearchResult that = (SearchResult) obj;
            return totalResults == that.totalResults &&
                    totalPages == that.totalPages &&
                    keyword.equals(that.keyword) &&
                    results.equals(that.results);
        }

        @Override
        public int hashCode() {
            int result = keyword.hashCode();
            result = 31 * result + totalResults;
            result = 31 * result + totalPages;
            result = 31 * result + results.hashCode();
            return result;
        }
    }
}
