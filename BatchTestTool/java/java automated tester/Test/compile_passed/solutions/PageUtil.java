import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.HashMap;
import java.util.Collections;

public class PageUtil {
    private List<Object> data;
    private int pageSize;
    private int totalItems;
    private int totalPages;

    public PageUtil(List<Object> data, int pageSize) {
        this.data = data;
        this.pageSize = pageSize;
        this.totalItems = data.size();
        this.totalPages = (totalItems + pageSize - 1) / pageSize;
    }

    public Map<String, Object> getPageInfo(int pageNumber) {
        if (pageNumber < 1 || pageNumber > totalPages) {
            return Collections.emptyMap();
        }

        int startIndex = (pageNumber - 1) * pageSize;
        int endIndex = Math.min(startIndex + pageSize, totalItems);
        List<Object> pageData = data.subList(startIndex, endIndex);

        Map<String, Object> pageInfo = new HashMap<>();
        pageInfo.put("current_page", pageNumber);
        pageInfo.put("per_page", pageSize);
        pageInfo.put("total_pages", totalPages);
        pageInfo.put("total_items", totalItems);
        pageInfo.put("has_previous", pageNumber > 1);
        pageInfo.put("has_next", pageNumber < totalPages);
        pageInfo.put("data", pageData);

        return pageInfo;
    }

    public SearchInfo search(String keyword) {
        List<Object> results = new ArrayList<>();
        for (Object item : data) {
            if (item.toString().contains(keyword)) {
                results.add(item);
            }
        }

        int numResults = results.size();
        int numPages = (numResults + pageSize - 1) / pageSize;

        SearchInfo searchInfo = new SearchInfo();
        searchInfo.setKeyword(keyword);
        searchInfo.setTotalResults(numResults);
        searchInfo.setTotalPages(numPages);
        searchInfo.setResults(results);

        return searchInfo;
    }

    public List<Object> getPage(int pageNumber) {
        if (pageNumber < 1 || pageNumber > totalPages) {
            return Collections.emptyList();
        }

        int startIndex = (pageNumber - 1) * pageSize;
        int endIndex = Math.min(startIndex + pageSize, totalItems);
        return data.subList(startIndex, endIndex);
    }

    public static class SearchInfo {
        private String keyword;
        private int totalResults;
        private int totalPages;
        private List<Object> results;

        public String getKeyword() {
            return keyword;
        }

        public void setKeyword(String keyword) {
            this.keyword = keyword;
        }

        public int getTotalResults() {
            return totalResults;
        }

        public void setTotalResults(int totalResults) {
            this.totalResults = totalResults;
        }

        public int getTotalPages() {
            return totalPages;
        }

        public void setTotalPages(int totalPages) {
            this.totalPages = totalPages;
        }

        public List<Object> getResults() {
            return results;
        }

        public void setResults(List<Object> results) {
            this.results = results;
        }
    }
}