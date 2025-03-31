# Python Test
## Evaluation
To evaluate the translation results for the Python language, we provide the corresponding test suite. Please locate the `classeval-T_evaluation` folder.

### Format Conversion  
First, ensure that the Python code to be tested has been converted to JSON format. If it does not meet this format, navigate to the `preprocess` folder and execute:  
```bash
python py2jsonl.py
```
- `folder_path`: Replace with the path of the folder containing the Python code to be tested.  
- `output_path`: Replace with the output JSON file path, for example, `"output.jsonl"`.  

### Obtain Test File  
After confirming that your code has been correctly converted to JSON format, execute:  
```bash
python preprocess.py
```
- `ground_path`: Replace with the path to the provided `"model_output_ground.json"` file, located in the `output/model_output` folder;  
- `input_path`: Replace with the output file path obtained in the previous step, for example, `"output.jsonl"`;  
- `output_path`: Replace with the output file path, for example, `"model_output.json"`. Note that this file path should be located in the `output/model_output` folder.  

### Execute Test  
Navigate to the `classeval-T_evaluation` directory and run:  
```bash
python evaluation.py --source_file_name model_output --eval_data ClassEval_data
```
- `--source_file_name`: Specifies the filenames pertaining to model outputs.  
- `--eval_data`: Refers to the benchmark data file, named `ClassEval_data` in the current rendition.  

## Output  
The evaluation results are systematically cataloged in the `output/result` directory:  
- `detailed_result.json`: Dive deep with a meticulous examination of every test case across models' outputs.  
The runtime logs for every test case are in the log directory.  

Additionally, we provide a `calculate.py` file in the `preprocess` folder for statistical analysis of method-level test results. Navigate to the `preprocess` folder and execute:  
```bash
python calculate.py
```
- `file_path`: Replace with the path of the test output file, for example, `"detailed_result.json"`;  
- `output_file_path`: Replace with the output `.txt` file path, which will contain detailed information on method-level testing, for example, `"success_ratio_report.txt"`.  

## Compile Test 
Navigate to the `preprocess` folder and execute:  
```bash
python compile_test.py
```
- `-directory`: Replace with the path of the folder containing the Python files to be tested;  
- `-output_file`: Replace with the output file path, which will contain detailed test information.  

