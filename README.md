# Welcome to Push_Swap's README

🚀 **Project Name**: Push_Swap

👤 **Author**: [Pablo Palma](https://www.linkedin.com/in/pablopalmarodríguez/)

📆 **Version**: Final Release

---

### 🧠 Concept:
Push_Swap is an algorithmic challenge that requires sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, you'll need to manipulate various types of algorithms and choose the most appropriate one for an optimized sorting.

---

### 📚 Repository Contents:

- `Makefile`: The build script for compiling the project.
- `README.md`: This file - the guide and explanation of the project.
- `bonus/checker_bonus.c`: Bonus part for additional features.
- `inc/`: Header files for the project, including the libft.
- `shared/`: Shared utility functions used across the project.
- `src/`: Source files containing the logic of the sorting algorithms.
- `subjet/`: The project instructions and explanation documents.
- `test/`: Scripts and executables for testing the project.

---

### 🔨 How to Use:

1. **Compile the Project**: Run `make` in the root of the project directory.
2. **Execute Push_Swap**: After compilation, you can run `./push_swap ARG` where `ARG` is a list of integers.

---

### 🌟 Features:

- Efficient sorting algorithms tailored for different set sizes.
- Bonus part with additional checker program for validation.
- Comprehensive error management.
- Clean and maintainable code with a clear modular architecture.

---

### 📈 Efficiency at its Best:

- `ft_sort_sizebased`: Dynamically chooses the sorting method based on the size of the data set.
- Handles 2 to 5 numbers with simple and efficient algorithms.
- Employs a complex algorithm for larger sets, dividing the stack into chunks and sorting them incrementally.

---
### 🚀 Optimal Algorithm Fusion:

- `ft_selective_quick`: Tailors sorting strategy to data size, using QuickSort's principles and chunk-based refinement.

**Quick Look at Sorting Choices**
Our Push_Swap employs a unique mix of QuickSort's efficient partitioning and chunk-based sorting for variable-sized arrays. This versatile tactic optimizes performance across diverse scenarios in Push_Swap tasks.

| Algorithm       | Worst    | Average   | Best      | Ideal For                          |
|-----------------|----------|-----------|-----------|------------------------------------|
| Bubble Sort     | O(n^2)   | O(n^2)    | O(n)      | Small, simple lists                |
| Insertion Sort  | O(n^2)   | O(n^2)    | O(n)      | Small, stable lists                |
| ...             | ...      | ...       | ...       | ...                                |
| QuickSort       | O(n^2)   | O(n log n)| O(n log n)| Large lists, quick average cases   |
| Radix Sort      | O(nk)    | O(nk)     | O(nk)     | Integer, non-comparative sorting   |

The adopted approach not only captures QuickSort's swift average-case resolution but also brings in a systematic process for larger sets, ensuring the Push_Swap program maintains top efficiency without compromise.

You can insert this section after the introduction of your README, where you outline the purpose of the project. This spot is perfect as it leads readers from understanding what Push_Swap is about to how you approached one of its most critical aspects: the sorting algorithm.

---

### 🧩 Modular Code Design:

- `ft_push_swap.c`: The main logic for initiating the sorting process.
- `ft_sort_five_numbers.c`: Manages small stacks by offloading the smallest elements before fine-tuning the sort.
- `ft_sort_three_numbers.c`: Optimizes three-element stacks with minimal swaps and rotations for immediate order.
- `ft_sort_hundred.c`: Handles sorting of stacks with a larger number of elements, optimizing moves.

---

### 🛠 Development Insights:

- Emphasis on optimizing the algorithm to reduce the number of operations.
- Each function is designed to handle a specific part of the sorting process, keeping the code organized.
- Continuous refactoring ensures the code remains efficient and readable.

---

### 🎯 Testing:

- Use the provided [`push_swap_test.sh`](https://github.com/Pablo-Palma/Push_swap/blob/main/test/push_swap_test.sh) script to run through a series of tests to ensure reliability.
- Utilize [`checker_Mac`](https://github.com/Pablo-Palma/Push_swap/blob/main/test/checker_Mac) to validate the output of the sorting algorithm.
- **Or opt for my custom checker (`checker_bonus`):** An effective way to confirm the sorting success. It reads and applies operations to the stacks, giving "OK" if sorted correctly or "KO" otherwise.

#### Using `checker_bonus`:
1. Build it using `make bonus`.
2. Run `push_swap` to generate operations.
3. Pipe them into `checker_bonus` with your stack like so:
   ```sh
   ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_bonus $ARG
   ```
4. Look for "OK" or "KO" to determine the sort status.

`checker_bonus` adds an extra layer of assurance in debugging and perfecting your Push_Swap algorithm.

---

### 📣 Feedback:

Your thoughts and feedback are much appreciated as they help in the ongoing improvement of Push_Swap. For contributions or any inquiries, please contact [Pablo Palma](mailto:pablopalmappr@gmail.com).

---

### 🌱 Grow with Push_Swap:

Join the journey of continuous learning and refining algorithmic skills with Push_Swap. Let's sort efficiently, one number at a time!

🔁 **"In the world of Push_Swap, an optimized move is worth a thousand numbers."**

---

Thank you for exploring Push_Swap. Happy Sorting!

---

Happy coding! 🎉

*Pablo Palma

