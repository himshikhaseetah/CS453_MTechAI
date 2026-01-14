# CS453_MTechAI
Software Engineering Lab - MTech AI Sem 2

Assignment Submission is for C program that performs the following:
1. Run Usage: ./srps input.txt output.txt
2. input.txt is the input provided as list of students and a set of 5 subject marks in the format:
        StudentId   StudentName
        Sub1 SubCredits SubMinorMarks SubMajorMarks
        Sub2 SubCredits SubMinorMarks SubMajorMarks
        Sub3 SubCredits SubMinorMarks SubMajorMarks
        Sub4 SubCredits SubMinorMarks SubMajorMarks
        Sub5 SubCredits SubMinorMarks SubMajorMarks
3. Input file is processed to include: 
        Data validation (validation.h, validation.c)
        Grading & class statistics calculation (grading.h, grading.c)
        File output (report.h, report.c)
4. Output file will contain student results and class statistics after processing
5. Grading has been calculated as follows:
        Each subject will have No. of credits (read from input), total marks (sum of SubMinorMarks and SubMajorMarks from input),
        as per total marks, subject grade & grade point are assigned (based on assignment pdf), pass = 1 if total marks >= 50 
        and credits points calculated using credits & grade point.
        Each student will have student id, name & a set of 5 subjects; the total marks, percentage, total credits (of 5 subjects),
        total credit points, grade & cgpa (total credit points / total credits) will be calculated based on subject compilation.


