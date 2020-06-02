# 569. 员工薪水中位数
# SQL架构
# Employee 表包含所有员工。Employee 表有三列：员工Id，公司名和薪水。
# 
# +-----+------------+--------+
# |Id   | Company    | Salary |
# +-----+------------+--------+
# |1    | A          | 2341   |
# |2    | A          | 341    |
# |3    | A          | 15     |
# |4    | A          | 15314  |
# |5    | A          | 451    |
# |6    | A          | 513    |
# |7    | B          | 15     |
# |8    | B          | 13     |
# |9    | B          | 1154   |
# |10   | B          | 1345   |
# |11   | B          | 1221   |
# |12   | B          | 234    |
# |13   | C          | 2345   |
# |14   | C          | 2645   |
# |15   | C          | 2645   |
# |16   | C          | 2652   |
# |17   | C          | 65     |
# +-----+------------+--------+
# 请编写SQL查询来查找每个公司的薪水中位数。挑战点：你是否可以在不使用任何内置的SQL函数的情况下解决此问题。
# 
# +-----+------------+--------+
# |Id   | Company    | Salary |
# +-----+------------+--------+
# |5    | A          | 451    |
# |6    | A          | 513    |
# |12   | B          | 234    |
# |9    | B          | 1154   |
# |14   | C          | 2645   |
# +-----+------------+--------+

# Write your MySQL query statement below
SELECT id, company, salary 
FROM employee
WHERE id IN (SELECT e1.id 
             FROM employee e1, employee e2 
             WHERE e1.company=e2.company 
             GROUP BY e1.id 
             HAVING SUM(CASE WHEN e1.salary>=e2.salary THEN 1 ELSE 0 END) >= COUNT(*)/2  
                AND SUM(CASE WHEN e1.salary<=e2.salary THEN 1 ELSE 0 END) >= COUNT(*)/2)
GROUP BY company, salary 
ORDER BY company, salary;
