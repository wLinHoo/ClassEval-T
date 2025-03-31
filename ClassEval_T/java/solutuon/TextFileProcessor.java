package org.example;

import java.io.*;
import java.nio.file.*;

import com.fasterxml.jackson.databind.ObjectMapper;

public class TextFileProcessor {
    private String file_path;

    public TextFileProcessor(String file_path) {
        this.file_path = file_path;
    }

    public Object read_file_as_json() throws IOException {
        ObjectMapper objectMapper = new ObjectMapper();
        return objectMapper.readValue(new File(file_path), Object.class);
    }

    public String read_file() throws IOException {
        return new String(Files.readAllBytes(Paths.get(file_path)));
    }

    public void write_file(String content) throws IOException {
        Files.write(Paths.get(file_path), content.getBytes());
    }

    public String process_file() throws IOException {
        String content = read_file();
        String processedContent = content.replaceAll("[^a-zA-Z]", "");
        write_file(processedContent);
        return processedContent;
    }
}