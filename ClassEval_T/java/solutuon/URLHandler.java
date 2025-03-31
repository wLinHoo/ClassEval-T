package org.example;

import java.util.HashMap;
import java.util.Map;

public class URLHandler {
    private String url;

    public URLHandler(String url) {
        this.url = url;
    }

    public String getScheme() {
        int schemeEnd = url.indexOf("://");
        if (schemeEnd != -1) {
            return url.substring(0, schemeEnd);
        }
        return null;
    }

    public String getHost() {
        int schemeEnd = url.indexOf("://");
        if (schemeEnd != -1) {
            String urlWithoutScheme = url.substring(schemeEnd + 3);
            int hostEnd = urlWithoutScheme.indexOf("/");
            if (hostEnd != -1) {
                return urlWithoutScheme.substring(0, hostEnd);
            }
            return urlWithoutScheme;
        }
        return null;
    }

    public String getPath() {
        int schemeEnd = url.indexOf("://");
        if (schemeEnd != -1) {
            String urlWithoutScheme = url.substring(schemeEnd + 3);
            int hostEnd = urlWithoutScheme.indexOf("/");
            if (hostEnd != -1) {
                return urlWithoutScheme.substring(hostEnd);
            }
        }
        return null;
    }

    public Map<String, String> getQueryParams() {
        int queryStart = url.indexOf("?");
        int fragmentStart = url.indexOf("#");
        if (queryStart != -1) {
            String queryString = url.substring(queryStart + 1, fragmentStart != -1 ? fragmentStart : url.length());
            Map<String, String> params = new HashMap<>();
            if (!queryString.isEmpty()) {
                String[] paramPairs = queryString.split("&");
                for (String pair : paramPairs) {
                    String[] keyValue = pair.split("=");
                    if (keyValue.length == 2) {
                        params.put(keyValue[0], keyValue[1]);
                    }
                }
            }
            return params;
        }
        return null;
    }

    public String getFragment() {
        int fragmentStart = url.indexOf("#");
        if (fragmentStart != -1) {
            return url.substring(fragmentStart + 1);
        }
        return null;
    }
}