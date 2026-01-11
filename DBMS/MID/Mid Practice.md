1. List all departments.

   ```
   SELECT dept_name
   FROM department
   ```

2. Find the names of all instructors.

   ```
    SELECT name
    FROM instructor
   ```

3. Retrieve all courses from the Biology department.

   ```
    SELECT course_id, title
    FROM course
    WHERE dept_name = "Biology"
   ```

4. Show the capacity of the 'Watson' building.

   ```
    SELECT room_number, capacity
    FROM classroom
    WHERE building = "Watson"
   ```

5. List all students in the 'Comp. Sci.' department.

   ```
    SELECT id, name
    FROM student
    WHERE dept_name = "Comp. Sci."
   ```

6. Find all courses with credits greater than 3.

   ```
    SELECT course_id, title, credits
    FROM course
    WHERE credits > 3
   ```

7. Retrieve the names and salaries of instructors earning more than 70,000.

   ```
    SELECT name, salary
    FROM instructor
    WHERE salary > 70000
   ```

8. Display all sections offered in the 'Fall' semester of 2017.

   ```
    SELECT sec_id
    FROM section
    WHERE semester = "Fall" AND year = 2017
   ```

9. Find the names of students who have earned more than 50 total credits.

   ```
    SELECT name
    FROM student
    WHERE tot_cred > 50
   ```

10. List all courses along with their prerequisites.

    ```
    SELECT c.course_id, p.prereq_id
    FROM course c
    JOIN prereq p ON c.course_id = p.course_id
    JOIN course c1 ON p.prereq_id = c1.course_id
    ```

11. Display the room numbers in the 'Taylor' building.

    ```
    SELECT room_number
    FROM classroom
    WHERE building = "Taylor"
    ```

12. Retrieve the name and department of all instructors.

    ```
    SELECT name, dept_name
    FROM instructor
    ```

13. Find all students with a total credit of 0.

    ```
    SELECT id, name
    FROM student
    WHERE tot_cred = 0
    ```

14. Show all sections that take place in the 'Packard' building.

    ```
    SELECT sec_id, course_id
    FROM section
    WHERE building = "Packard"
    ```

15. List all courses taught by 'Srinivasan'.

    ```
    SELECT c.course_id, c.title
    FROM course c
    JOIN teaches t ON c.course_id = t.course_id
    JOIN instructor i ON i.ID = t.ID
    WHERE i.name = "Srinivasan"
    ```

16. Retrieve all time slots that start at or after 10 AM.

    ```

    ```

17. Find all advisors for student '12345'.

    ```
    SELECT i.ID, i.name
    FROM instructor i
    JOIN advisor a ON a.i_id = i.ID
    WHERE a.s_id = 12345
    ```

18. List all departments located in the 'Taylor' building.

    ```
    SELECT dept_name
    FROM department d
    WHERE building = "Taylor"
    ```

19. Show all students along with their assigned advisors.

    ```
    SELECT s.name, i.name
    FROM student s
    JOIN advisor a ON s.ID = a.s_id
    JOIN instructor i ON a.i_id = i.ID
    ```

20. Retrieve the budget of the 'Finance' department.

    ```
    SELECT budget
    FROM department
    WHERE dept_name = "Finance"
    ```

21. Find the names of students who took 'CS-101' in 'Fall 2017'.

    ```

    ```

22. List the titles of courses taught by 'Crick'.

    ```
    SELECT c.course_id, c.title
    FROM course c
    JOIN teaches t ON t.course_id = c.course_id
    JOIN instructor i ON i.ID = t.ID
    WHERE i.name = "Crick"
    ```

23. Retrieve the total budget for all departments in the 'Taylor' building.

    ```
    SELECT SUM(budget)
    FROM department
    WHERE building = "Taylor"
    ```

24. Find the average salary of instructors in each department.

    ```
    SELECT dept_name, round(AVG(salary),2)
    FROM instructor
    GROUP BY dept_name
    ```

25. Show all students who are taking 'Spring 2018' courses in the 'Watson' building.

    ```
    SELECT s.id, s.name
    FROM student s
    JOIN takes t ON t.ID = s.ID
    JOIN section se ON t.course_id = se.course_id AND t.sec_id = se.sec_id
    WHERE t.semester = "Spring" AND t.year = 2018 AND se.building = "Watson"
    ```

26. List all courses that have more than one prerequisite.

    ```

    ```

27. Find the departments with a budget less than 75,000.

    ```

    ```

28. Retrieve all time slots that span more than an hour.

    ```

    ```

29. Display the names of instructors who have taught in the 'Taylor' building.

    ```
    SELECT DISTINCT i.name
    FROM instructor i
    JOIN teaches t ON t.ID = i.ID
    JOIN section s ON t.course_id = s.course_id
    WHERE s.building = "Taylor"
    ```

30. Show the highest total credits among all students.

    ```
    SELECT name, tot_cred
    FROM student s
    WHERE tot_cred = (SELECT MAX(tot_cred) FROM student)
    ```

31. Find the instructor teaching the most courses.

    ```
    SELECT id, COUNT(course_id) as cnt
    FROM teaches
    GROUP BY id
    ORDER BY cnt DESC
    LIMIT 1
    ```

32. List the courses that no students are enrolled in.

    ```

    ```

33. Retrieve the names of students who failed at least one course.

    ```

    ```

34. Find the building with the largest total classroom capacity.

    ```

    ```

35. List the names of students advised by 'Einstein'.

    ```

    ```

36. Display the titles of courses taken by 'Zhang'.

    ```

    ```

37. Show the names of students who have completed all courses in the 'Comp. Sci.' department.

    ```

    ```

38. Retrieve all instructors who have never taught a course.

    ```

    ```

39. Find all courses that have prerequisites from a different department.

    ```

    ```

40. List all departments where no students are enrolled.

    ```

    ```

41. Find students who are taking all courses taught by 'Srinivasan'.

    ```

    ```

42. Retrieve the name of the student with the highest GPA (assume grades map to points: A=4, B=3, etc.).

    ```

    ```

43. List the courses with overlapping time slots.

    ```

    ```
