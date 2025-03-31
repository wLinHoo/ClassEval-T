import tkinter as tk
import json
import os


class ErrorTracker:
    def __init__(self, master):
        self.master = master
        self.master.title("Error Tracker")
        self.master.configure(bg="#f7f7f7")

        # Define main categories with and without subcategories
        self.error_structure = {
            "Library-related": {
                "Copying libraries from other languages": 0,
                "Missing required library": 0,
                "API/library mismatch": 0,
            },
            "Syntax errors": {
                "Symbol errors": 0,
                "Language feature errors": 0,
                "Type mismatch errors": 0,
                "Grammar structure errors": 0,
                "Retaining source language syntax": 0,
            },
            "Function/variable usage issues": {
                "Functions missing return values": 0,
                "Return value type mismatch": 0,
                "Attempt to call non-existent function": 0,
                "Attempt to call undefined fields": 0,
                "Parameter errors": 0,
            },
            "Code consistency/completeness": {
                "Generated code inconsistency": 0,
                "Non-code content generated": 0,
                "Generated code incomplete": 0,
            },
            "Functional errors": 0,  # No subcategories
            "Runtime errors": 0,  # No subcategories
            "Other errors": 0  # No subcategories
        }

        # Track the total counts for main categories
        self.main_category_totals = {category: 0 for category in self.error_structure}

        # Load any existing data
        self.load_from_jsonl()

        # Set up the user interface
        self.create_widgets()
        self.update_display()

    def create_widgets(self):
        # Create frame and buttons for each main category and subcategory
        self.frames = {}

        for category, subcategories in self.error_structure.items():
            # Frame for each main category
            category_frame = tk.Frame(self.master, bg="#e8f0fe", pady=5, padx=10, relief="groove", bd=2)
            category_frame.pack(fill="x", pady=5, padx=10)

            # Category Label
            category_label = tk.Label(
                category_frame, text=f"{category}", font=("Arial", 12, "bold"),
                fg="#1a73e8", bg="#e8f0fe"
            )
            category_label.pack(anchor="w", pady=(5, 0))

            if isinstance(subcategories, dict):  # Category with subcategories
                self.frames[category] = {"label": category_label, "subcategories": {}}

                for subcategory in subcategories:
                    # Subcategory Frame
                    sub_frame = tk.Frame(category_frame, bg="#ffffff", pady=3, padx=5, relief="solid", bd=0.5)
                    sub_frame.pack(fill="x", pady=2)

                    label = tk.Label(sub_frame, text=subcategory, font=("Arial", 10), bg="#ffffff", fg="#333")
                    label.pack(side=tk.LEFT, padx=5)

                    count_label = tk.Label(sub_frame, text=str(self.error_structure[category][subcategory]),
                                           font=("Arial", 10, "bold"), bg="#ffffff", fg="#444")
                    count_label.pack(side=tk.LEFT, padx=10)

                    add_button = tk.Button(sub_frame, text="+",
                                           command=lambda cat=category, subcat=subcategory: self.increment_error(cat,
                                                                                                                 subcat),
                                           bg="#1a73e8", fg="white", font=("Arial", 8, "bold"), relief="flat", width=3)
                    add_button.pack(side=tk.LEFT, padx=5)

                    subtract_button = tk.Button(sub_frame, text="-",
                                                command=lambda cat=category, subcat=subcategory: self.decrement_error(
                                                    cat, subcat), bg="#d93025", fg="white", font=("Arial", 8, "bold"),
                                                relief="flat", width=3)
                    subtract_button.pack(side=tk.LEFT, padx=5)

                    self.frames[category]["subcategories"][subcategory] = count_label

            else:  # Category without subcategories
                count_label = tk.Label(category_frame, text=str(self.error_structure[category]),
                                       font=("Arial", 12, "bold"), fg="#333", bg="#e8f0fe")
                count_label.pack(side=tk.LEFT, padx=5)

                add_button = tk.Button(category_frame, text="+", command=lambda cat=category: self.increment_error(cat),
                                       bg="#1a73e8", fg="white", font=("Arial", 10, "bold"), relief="flat", width=3)
                add_button.pack(side=tk.LEFT, padx=5)

                subtract_button = tk.Button(category_frame, text="-",
                                            command=lambda cat=category: self.decrement_error(cat), bg="#d93025",
                                            fg="white", font=("Arial", 10, "bold"), relief="flat", width=3)
                subtract_button.pack(side=tk.LEFT, padx=5)

                self.frames[category] = {"label": count_label}

    def load_from_jsonl(self):
        if os.path.exists('errors.jsonl'):
            with open('errors.jsonl', 'r', encoding='utf-8') as f:
                self.error_structure = json.load(f)

        # Recalculate main category totals after loading
        for category, subcategories in self.error_structure.items():
            if isinstance(subcategories, dict):
                self.main_category_totals[category] = sum(subcategories.values())
            else:
                self.main_category_totals[category] = subcategories

    def increment_error(self, category, subcategory=None):
        if subcategory:
            self.error_structure[category][subcategory] += 1
        else:
            self.error_structure[category] += 1
        self.update_display()

    def decrement_error(self, category, subcategory=None):
        if subcategory:
            if self.error_structure[category][subcategory] > 0:
                self.error_structure[category][subcategory] -= 1
        else:
            if self.error_structure[category] > 0:
                self.error_structure[category] -= 1
        self.update_display()

    def update_display(self):
        # Update subcategory counts and main category totals
        for category, data in self.frames.items():
            if "subcategories" in data:
                total = 0
                for subcategory, count_label in data["subcategories"].items():
                    count = self.error_structure[category][subcategory]
                    count_label.config(text=str(count))
                    total += count

                # Update main category total
                self.main_category_totals[category] = total
                data["label"].config(text=f"{category} (Total: {total})")
            else:
                # Update main category without subcategories
                data["label"].config(text=str(self.error_structure[category]))

        # Save to JSONL
        self.save_to_jsonl()

    def save_to_jsonl(self):
        with open('errors.jsonl', 'w', encoding='utf-8') as f:
            json.dump(self.error_structure, f, ensure_ascii=False, indent=4)


if __name__ == "__main__":
    root = tk.Tk()
    app = ErrorTracker(root)
    root.mainloop()
