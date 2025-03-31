package org.example;

import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.Workbook;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ExcelProcessor {

    public ExcelProcessor() {
    }

    public List<List<Object>> readExcel(String fileName) {
        List<List<Object>> data = new ArrayList<>();
        try (FileInputStream file = new FileInputStream(fileName);
             Workbook workbook = new XSSFWorkbook(file)) {
            Sheet sheet = workbook.getSheetAt(0);
            for (Row row : sheet) {
                List<Object> rowData = new ArrayList<>();
                for (Cell cell : row) {
                    switch (cell.getCellType()) {
                        case STRING:
                            rowData.add(cell.getStringCellValue());
                            break;
                        case NUMERIC:
                            rowData.add((int) cell.getNumericCellValue());
                            break;
                        default:
                            rowData.add(null);
                            break;
                    }
                }
                data.add(rowData);
            }
        } catch (IOException e) {
            return null;
        }
        return data;
    }



    public boolean writeExcel(List<List<Object>> data, String fileName) {
        try (Workbook workbook = new XSSFWorkbook();
             FileOutputStream fileOut = new FileOutputStream(fileName)) {
            Sheet sheet = workbook.createSheet("Sheet1");
            for (int i = 0; i < data.size(); i++) {
                Row row = sheet.createRow(i);
                List<Object> rowData = data.get(i);
                for (int j = 0; j < rowData.size(); j++) {
                    Cell cell = row.createCell(j);
                    Object value = rowData.get(j);
                    if (value instanceof String) {
                        cell.setCellValue((String) value);
                    }
                    else if (value instanceof Integer) {
                        cell.setCellValue((Integer) value);
                    }
                }
            }
            workbook.write(fileOut);
            return true;
        } catch (IOException e) {
            return false;
        }
    }

    public String processExcelData(int N, String saveFileName) {
        List<List<Object>> data = readExcel(saveFileName);
        if (data == null || N >= data.get(0).size()) {
            return null;
        }
        List<List<Object>> newData = new ArrayList<>();
        for (List<Object> row : data) {
            List<Object> newRow = new ArrayList<>(row);
            Object value = row.get(N);
            if (value instanceof String) {
                newRow.add(((String) value).toUpperCase());
            }
            else {
                newRow.add(value);
            }
            newData.add(newRow);
        }
        String newFileName = saveFileName.replace(".xlsx", "_process.xlsx");
        boolean success = writeExcel(newData, newFileName);
        return success ? newFileName : null;
    }
}