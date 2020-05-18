# 180. 连续出现的数字
# SQL架构
# 编写一个 SQL 查询，查找所有至少连续出现三次的数字。
# 
# +----+-----+
# | Id | Num |
# +----+-----+
# | 1  |  1  |
# | 2  |  1  |
# | 3  |  1  |
# | 4  |  2  |
# | 5  |  1  |
# | 6  |  2  |
# | 7  |  2  |
# +----+-----+
# 例如，给定上面的 Logs 表， 1 是唯一连续出现至少三次的数字。
# 
# +-----------------+
# | ConsecutiveNums |
# +-----------------+
# | 1               |
# +-----------------+

# Write your MySQL query statement below
SELECT DISTINCT l1.num ConsecutiveNums
FROM logs l1, logs l2, logs l3
WHERE l1.id + 1 = l2.id AND l1.num = l2.num
    AND l1.id + 2 = l3.id AND l1.num = l3.num;
