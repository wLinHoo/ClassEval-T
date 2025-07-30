import json

# Read JSON file
def load_json_file(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        data = json.load(f)
    return data

# Function to calculate success ratio for a single sub-dictionary
def calculate_success_ratio_for_class(class_eval_value):
    total_tests = 0
    success_tests = 0

    # Iterate through each field in the sub-dictionary
    for test_key, test_value in class_eval_value.items():
        # Skip keys with names "TestClass" or ending with "Test" or "Main"
        if test_key == "TestClass" or test_key.endswith("Test") or test_key.endswith("Main"):
            continue

        # Get the success value for this field
        success_count = test_value.get("success", 0)

        # Update total test count
        total_tests += 1

        # If success is greater than 0, consider this test successful
        if success_count > 0:
            success_tests += 1

    # Calculate success ratio
    if total_tests > 0:
        success_ratio = success_tests / total_tests
    else:
        success_ratio = 0

    return success_ratio, success_tests, total_tests

# Main function: load data from JSON file, calculate success ratios, and write results to txt file
def main():
    # Replace with your JSON file path
    file_path = r"..\output\result\detailed_result.json"
    # Output file path
    output_file_path = r"..\output\result\success_method_ratio_report.txt"

    # Load JSON data
    data = load_json_file(file_path)
    model_output = data.get("model_output", {})

    # Global counters for calculating total success ratio
    total_tests_global = 0
    success_tests_global = 0

    # Open a file to write results
    with open(output_file_path, 'w', encoding='utf-8') as output_file:
        # Iterate through each sub-dictionary, such as ClassEval_0, ClassEval_1
        for class_eval_key, class_eval_value in model_output.items():
            # Skip specified ClassEval items
            #if class_eval_key in ['ClassEval_34', 'ClassEval_44', 'ClassEval_45', 'ClassEval_69', 'ClassEval_52',
                                  #'ClassEval_58']:
                #continue

            success_ratio, success_tests, total_tests = calculate_success_ratio_for_class(class_eval_value)

            # Add to global counters
            total_tests_global += total_tests
            success_tests_global += success_tests

            # Output each sub-dictionary result to file
            output_file.write(f"{class_eval_key}:\n")
            output_file.write(f"Successful tests: {success_tests}\n")
            output_file.write(f"Total tests: {total_tests}\n")
            output_file.write(f"Success ratio: {success_ratio:.2%}\n\n")

            # Also print each sub-dictionary result to console
            print(f"{class_eval_key}:")
            print(f"Successful tests: {success_tests}")
            print(f"Total tests: {total_tests}")
            print(f"Success ratio: {success_ratio:.2%}")
            print()

        # Calculate global success ratio
        if total_tests_global > 0:
            global_success_ratio = success_tests_global / total_tests_global
        else:
            global_success_ratio = 0

        # Write global results to file
        output_file.write(f"Method level:\n")
        output_file.write(f"Total successful tests: {success_tests_global}\n")
        output_file.write(f"Total tests: {total_tests_global}\n")
        output_file.write(f"Total success ratio: {global_success_ratio:.2%}\n\n")

        # Write global results to file
        output_file.write(f"Class level:\n")
        output_file.write(f"Total tests: 94\n")
        output_file.write(f"Successful tests: \n")
        output_file.write(f"Success ratio: \n")

        # Also print global results to console
        print(f"Total successful tests: {success_tests_global}")
        print(f"Total tests: {total_tests_global}")
        print(f"Total success ratio: {global_success_ratio:.2%}")

    print(f"All results have been written to file: {output_file_path}")

# Execute main function
if __name__ == "__main__":
    main()
