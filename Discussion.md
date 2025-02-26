## Discussion

### Solutions Considered

1. **Reading the Entire File into Memory**

   - This approach was discarded due to the excessive memory requirements for a 1TB log file.

2. **Line-by-Line Streaming with Filtering**

   - Using file streams to read the file line by line and filter based on the given date.
   - Efficient in terms of memory usage.

3. **Using an Indexed Approach**
   - Creating an index file to store byte offsets for each day's logs.
   - Improves query speed but requires preprocessing.

### Final Solution Summary

We chose the **line-by-line streaming approach** because it is simple, memory-efficient, and does not require additional preprocessing or storage. It provides a good balance between performance and resource usage.

### Steps to Run

1. **Compile the Code:**

   ```sh
   g++ -o extract_logs src/solution.cpp
   ```

2. **Run the Program:**

   ```sh
   ./extract_logs <log_file> YYYY-MM-DD
   ```

3. **Output:**
   - The extracted logs will be saved in `output/output_YYYY-MM-DD.txt`.
