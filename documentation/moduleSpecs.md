# Module Specifications for Student Result Processing System

## 1. ValidateId

**Purpose:** Student ID Validation

**Input Parameters:**
- `char *id` - Student ID string to validate

**Pre-condition:**
- `id` should not be NULL (checked within function)

**Logic:**
1. Check if `id` is NULL or empty string; if yes, return invalid (0)
2. Check if `id` length is not less than MAX_ID-1 characters; if no, return invalid (0)
3. Iterate through each character in `id`:
   - Verify each character is alphanumeric (letter or digit)
   - If any non-alphanumeric character found, return invalid (0)
4. If all validations pass, return valid (1)

**Output:**
- Returns 1 if ID is valid (non-empty, correct length, all alphanumeric)
- Returns 0 if ID is invalid

---

## 2. ValidateName

**Purpose:** Student Name Validation

**Input Parameters:**
- `char *name` - Student name string to validate

**Pre-condition:**
- `name` should not be NULL (checked within function)

**Logic:**
1. Check if `name` is NULL or empty string; if yes, return invalid (0)
2. Check if `name` length exceeds MAX_NAME; if yes, return invalid (0)
3. Iterate through each character in `name`:
   - Verify each character is either an alphabetic character or a space
   - If any non-alphabetic and non-space character found, return invalid (0)
4. If all validations pass, return valid (1)

**Output:**
- Returns 1 if name is valid (non-empty, within length limit, contains only letters and spaces)
- Returns 0 if name is invalid

---

## 3. ValidateSubject

**Purpose:** Subject Data Validation

**Input Parameters:**
- `char *name` - Subject name string to validate
- `int credits` - Number of credits to validate
- `int minor` - Minor examination marks to validate
- `int major` - Major examination marks to validate

**Pre-condition:**
- `name` should not be NULL (checked within function)

**Logic:**
1. Check if `name` is NULL or empty string; if yes, return invalid (0) Length limit is not set for subject name
2. Check if `credits` is positive (> 0); if not, return invalid (0)
3. Check if `minor` marks are in valid range [0, 40]; if outside range, return invalid (0)
4. Check if `major` marks are in valid range [0, 60]; if outside range, return invalid (0)
5. If all validations pass, return valid (1)

**Output:**
- Returns 1 if all subject data is valid
- Returns 0 if any subject data is invalid

---

## 4. ValidateFile

**Purpose:** Filename Validation

**Input Parameters:**
- `char *filename` - Filename string to validate

**Pre-condition:**
- `filename` should not be NULL (checked within function)

**Logic:**
1. Get length of filename string
2. Check if filename length is less than 5 characters (minimum: 1 char + ".txt"); if yes, return invalid (0)
3. Check if `filename` is NULL or length < 5; if yes, return invalid (0)
4. Check if filename ends with ".txt" extension; if not, return invalid (0)
5. Iterate through all characters in filename before the ".txt" extension:
   - Verify each character is alphanumeric (letter or digit)
   - If any non-alphanumeric character found before extension, return invalid (0)
6. If all validations pass, return valid (1)

**Output:**
- Returns 1 if filename is valid (.txt extension, at least 1 alphanumeric character before extension)
- Returns 0 if filename is invalid

---

## 5. CheckDuplicateId

**Purpose:** Duplicate Student ID Detection

**Input Parameters:**
- `Student students[]` - Array of Student structures to search
- `int n` - Number of students in the array
- `char *id` - Student ID to check for duplicates

**Pre-condition:**
- `students` array must contain at least `n` valid Student structures
- `n` must be non-negative integer
- `id` must not be NULL

**Logic:**
1. Iterate through all students in the array (from index 0 to n-1):
   - Compare current student's ID with the provided ID using string comparison
   - If any student has matching ID, return not unique (0)
2. If loop completes without finding any match, return unique (1)

**Output:**
- Returns 1 if ID is unique (not found in existing student list)
- Returns 0 if ID is duplicate (found in existing student list)

### 6. InitClass

**Purpose:** Class Initialization Constructor

**Input Parameters:**
- `int count` - Number of students in the class

**Pre-condition:**
- `count` must be a non-negative integer - This condition is verify before calling function in main

**Logic:**
1. Create a new Class structure object
2. Set the student count to the provided count parameter
3. Initialize average percentage to 0.0
4. Initialize maximum percentage to 0.0
5. Initialize minimum percentage to 0.0
6. Initialize all grade distribution counters (indices 0-7 for grades O to F) to 0

**Output:**
- Returns a Class structure object with all fields properly initialized

---

## 7. InitStudent

**Purpose:** Student Initialization Constructor

**Input Parameters:**
- `char *id` - Student ID string
- `char *name` - Student name string

**Pre-condition:**
- `id` must not be NULL - Validated before calling function in main
- `name` must not be NULL - Validated before calling function in main

**Logic:**
1. Create a new Student structure object
2. Copy student ID into student structure (up to MAX_ID characters)
3. Copy student name into student structure (up to MAX_NAME characters)
4. Set subject count to MAX_SUBJECTS
5. Initialize total marks to 0
6. Initialize percentage to 0.0
7. Initialize total credits to 0
8. Initialize total credit points to 0
9. Initialize CGPA to 0.0
10. Initialize grade string to empty string

**Output:**
- Returns a Student structure object with all fields properly initialized

---

## 8. InitSubject

**Purpose:** Subject Initialization Constructor

**Input Parameters:**
- `char *name` - Subject name string
- `int credits` - Number of credits for the subject
- `int minor` - Minor examination marks (internal evaluation)
- `int major` - Major examination marks (external evaluation)

**Pre-condition:**
- `name` must not be NULL
- `credits` must be a positive integer
- `minor` must be in valid range (0-40)
- `major` must be in valid range (0-60)

**Logic:**
1. Create a new Subject structure object
2. Copy subject name into subject structure (up to MAX_SUBJECT_NAME characters)
3. Set credits field to provided credits value
4. Set minor marks field to provided minor value
5. Set major marks field to provided major value
6. Initialize total marks to 0
7. Initialize grade point to 0
8. Initialize credit points to 0
9. Initialize pass flag to 0 (false)
10. Initialize grade string to empty string

**Output:**
- Returns a Subject structure object with all fields properly initialized

---

## 9. ComputeSubjectResult

**Purpose:** Subject Result Computation

**Input Parameters:**
- `Subject *s` - Pointer to Subject structure whose results need to be computed

**Pre-condition:**
- `s` must not be NULL
- `s->minor` and `s->major` must contain valid marks
- `s->credits` must be properly initialized

**Logic:**
1. Calculate total subject marks as minor + major
2. Compute subject grade based on total marks
3. Determine pass/fail status: subject passes if total >= 50, otherwise fails
4. Calculate credit points as credits * grade_point (where grade_point is determined by grade)
5. Store all computed values back into subject structure

**Output:**
- Modifies Subject structure with computed results (total marks, grade, grade_point, credit_points, and pass status)
- No return value (void)

---

## 10. ComputeSubGrade

**Purpose:** Subject Grade Computation

**Input Parameters:**
- `Subject *s` - Pointer to Subject structure whose grade needs to be assigned

**Pre-condition:**
- `s` must not be NULL
- `s->total` must be properly computed with valid value (0 to 100)

**Logic:**
1. Compare subject's total marks against predefined grade thresholds:
   - If total >= 90: Assign grade "O" and grade_point = 10
   - Else if total >= 85: Assign grade "A+" and grade_point = 9
   - Else if total >= 75: Assign grade "A" and grade_point = 8
   - Else if total >= 65: Assign grade "B+" and grade_point = 7
   - Else if total >= 60: Assign grade "B" and grade_point = 6
   - Else if total >= 55: Assign grade "C" and grade_point = 5
   - Else if total >= 50: Assign grade "D" and grade_point = 4
   - Else: Assign grade "F" and grade_point = 0
2. Copy assigned grade string into subject's grade field
3. Store corresponding grade_point value

**Output:**
- Modifies Subject structure with computed grade and grade_point value
- No return value (void)

---

## 11. ComputeStudentResult

**Purpose:** Student Result Computation

**Input Parameters:**
- `Student *st` - Pointer to Student structure whose results need to be computed

**Pre-condition:**
- `st` must not be NULL
- `st->subject_count` must be correctly set
- All subjects in `st->subjects[]` array must have valid minor and major marks - validated before calling function
- All subjects must be initialized with proper credits and marks

**Logic:**
1. Initial values for total marks and total credit points are assumed 0 from constructor function
2. For each subject in the student's subject list:
   - Compute subject result (total marks, grade, credit points)
   - Add subject total marks to student's total marks
   - Calculate student percentage as (total_marks / (subject_count * 100)) * 100
   - Add subject credits to total credits
   - Add subject credit points to total credit points
3. Compute student's overall grade based on percentage
4. If total credits > 0, calculate CGPA as total_credit_points / total_credits

**Output:**
- Modifies Student structure with computed results (total marks, percentage, total credits, total credit points, grade, and CGPA)
- No return value (void)

---

## 12. ComputeStudentGrade

**Purpose:** Student Grade Computation

**Input Parameters:**
- `Student *st` - Pointer to Student structure whose grade needs to be assigned

**Pre-condition:**
- `st` must not be NULL
- `st->percentage` must be properly computed and populated with a valid value (0.0 to 100.0)

**Logic:**
1. Compare student's percentage against predefined grade thresholds:
   - If percentage >= 90: Assign grade "O" (Outstanding)
   - Else if percentage >= 85: Assign grade "A+" (Excellent)
   - Else if percentage >= 75: Assign grade "A" (Very Good)
   - Else if percentage >= 65: Assign grade "B+" (Good)
   - Else if percentage >= 60: Assign grade "B" (Average Good)
   - Else if percentage >= 55: Assign grade "C" (Average)
   - Else if percentage >= 50: Assign grade "D" (Pass)
   - Else: Assign grade "F" (Fail)
2. Copy assigned grade string into student's grade field

**Output:**
- Modifies Student structure's grade field with computed grade
- No return value (void)

---

## 13. ComputeClassStatistics

**Purpose:** Class Statistics Computation

**Input Parameters:**
- `Class *c` - Pointer to Class structure to be populated with statistics
- `Student students[]` - Array of Student structures containing student data
- `int n` - Number of students in the array

**Pre-condition:**
- `c` must not be NULL - In current implementation, ComputeClassStatistics follows class constructor which ensures class object is not null.
- `students` array must contain at least `n` valid Student structures
- `n` must be greater than 0 - This condition is verified before calling function
- All students must have their percentage and grade fields populated

**Logic:**
1. Initialize sum variable to 0 and set max/min percentages to first student's percentage
2. Iterate through all students:
   - Add each student's percentage to sum
   - Update maximum percentage if current student's percentage is greater
   - Update minimum percentage if current student's percentage is smaller
   - Count grade occurrences and increment corresponding grade_distribution index (0=O, 1=A+, 2=A, 3=B+, 4=B, 5=C, 6=D, 7=F)
3. Calculate average percentage as sum divided by number of students
4. Store results back into Class structure

**Output:**
- Modifies Class structure with computed statistics (max, min, average percentages and grade distribution)
- No return value (void)

---


## 14. PrintResultList

**Purpose:** Student Result List Generator for all students with valid data(ID, name, marks)

**Input Parameters:**
- `FILE *fp` - File pointer for output destination
- `Student *st` - Pointer to Student structure containing computed results and subject data

**Pre-condition:**
- `fp` must not be NULL and must be a valid, open file pointer
- `st` must not be NULL
- `st` must have been populated by ComputeStudentResult function
- All subjects in `st->subjects[]` must have been computed

**Logic:**
1. Write student header with ID and name
2. Write column headers for the subject table (Subject, Minor, Major, Total, Credits, CPts, Grade, GPts, Result)
3. For each subject in student's subject list:
   - Extract subject data
   - Determine pass/fail status based on pass flag
   - Write formatted table row with subject details (name, marks, credits, grade_point, pass status)
4. Write summary section with:
   - Total marks across all subjects
   - Overall percentage formatted to 2 decimal places
   - Total credit points
   - CGPA formatted to 2 decimal places
5. Write footer separator line

**Output:**
- Prints formatted student result details and subject-wise breakdown to the provided file pointer
- No return value (void)

---

## 15. PrintClassStats

**Purpose:** Class Statistics Report Generator

**Input Parameters:**
- `FILE *fp` - File pointer for output destination
- `Class *c` - Pointer to Class structure containing computed statistics

**Pre-condition:**
- `fp` must not be NULL and must be a valid, open file pointer
- `c` must not be NULL and is populated by ComputeClassStatistics function

**Logic:**
1. Write header line with visual separator to the file
2. Write class average percentage formatted to 2 decimal places
3. Write highest percentage in class formatted to 2 decimal places
4. Write lowest percentage in class formatted to 2 decimal places
5. Write grade distribution header
6. Write count of each grade (O through F) on formatted output lines using grade_distribution array

**Output:**
- Prints formatted class statistics to the provided file pointer
- No return value (void)

---

