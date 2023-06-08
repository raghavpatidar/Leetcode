# Daily SQL problem June .

- [Daily SQL problem June .](#daily-sql-problem-june-)
- [Day 1](#day-1)
  - [175. Combine Two Tables](#175-combine-two-tables)
  - [181. Employees Earning More Than Their Managers](#181-employees-earning-more-than-their-managers)
- [Day 2](#day-2)
  - [182. Duplicate Emails](#182-duplicate-emails)
  - [183. Customers Who Never Order](#183-customers-who-never-order)
- [Day 3](#day-3)
  - [184. Department Highest Salary](#184-department-highest-salary)
  - [180. Consecutive Numbers](#180-consecutive-numbers)
- [Day 4](#day-4)
  - [197. Rising Temperature](#197-rising-temperature)
  - [196. Delete Duplicate Emails](#196-delete-duplicate-emails)


# Day 1
## [175. Combine Two Tables](https://leetcode.com/problems/combine-two-tables/) 
> Write an SQL query to report the first name, last name, city, and state of each person in the <code>Person</code> table. If the address of a personId is not present in the <code>Address</code>  table, report null instead.


<details><summary>Schema</summary>

```text
Table: Person
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| personId    | int     |
| lastName    | varchar |
| firstName   | varchar |
+-------------+---------+

personId is the primary key column for this table.
This table contains information about the ID of some persons and their first and last names.

Table: Address
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| addressId   | int     |
| personId    | int     |
| city        | varchar |
| state       | varchar |
+-------------+---------+

addressId is the primary key column for this table.
Each row of this table contains information about the city and state of one person with ID = PersonId.
```
</details>

<code >Query</code>
```sql
select firstName, lastName , city , state from Person as p left join Address as a on p.personId = a.personId;
```

<br>


## [181. Employees Earning More Than Their Managers](https://leetcode.com/problems/employees-earning-more-than-their-managers/)
> Write an SQL query to find the employees who earn more than their managers. Return the result table in any order.The query result format is in the following example.</>
<details>
<summary>Schema</summary>

```text
Table:  Employee

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| salary      | int     |
| managerId   | int     |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the ID of an employee, their name, salary, and the ID of their manager.
```
</details>

<code >Query</code>
```sql
select e.name as Employee from employee as e inner join employee as m on e.managerId = m.id and e.salary > m.salary;
```
<br>
<br>


# Day 2
## [182. Duplicate Emails](https://leetcode.com/problems/duplicate-emails/description/)
> Write an SQL query to report all the duplicate emails. Note that it's guaranteed that the email field is not NULL. 
> Return the result table in any order. 
> The query result format is in the following example.
<details>
<summary>Schema</summary>

```text
Table: Person

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id is the primary key column for this table.
Each row of this table contains an email. The emails will not contain uppercase letters.
```
</details>

<code >Query</code>
```sql
select  email from person
GROUP BY  email 
having count(email) > 1;
```
<br>

## [183. Customers Who Never Order](https://leetcode.com/problems/customers-who-never-order/description/)
>  Write an SQL query to report all customers who never order anything Return the result table in any order. The query result format is in the following example.

<details>
<summary>Schema</summary>

```text
Table: Customers

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the ID and name of a customer.
 

Table: Orders

+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| customerId  | int  |
+-------------+------+
id is the primary key column for this table.
customerId is a foreign key of the ID from the Customers table.
Each row of this table indicates the ID of an order and the ID of the customer who ordered it.
 
```
</details>

<code >Query</code>

```sql
# sub query

select name as Customers from Customers where id Not in (select Distinct customerId from Orders);


# left join
select name as Customers
from Customers as c
left join 
Orders as o 
on c.id = o.customerId 
where o.id is null;
```
<br>
<br>

# Day 3
## [184. Department Highest Salary](https://leetcode.com/problems/department-highest-salary/)
> Write an SQL query to find employees who have the highest salary in each of the departments. Return the result table in any order. The query result format is in the following example.

<details>
<summary>Schema</summary>

```text
Table: Employee

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| id           | int     |
| name         | varchar |
| salary       | int     |
| departmentId | int     |
+--------------+---------+
id is the primary key column for this table.
departmentId is a foreign key of the ID from the Department table.
Each row of this table indicates the ID, name, and salary of an employee. It also contains the ID of their department.

Table: Department

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
id is the primary key column for this table. It is guaranteed that department name is not NULL.
Each row of this table indicates the ID of a department and its name.

```
</details>

<code >Query</code>

```sql
# using inner join

SELECT d.name as Department,e.name as Employee ,e.salary as Salary
FROM 
    (SELECT max(salary) as maxi, departmentId FROM employee group by departmentId)  temp
INNER JOIN
    employee as e 
    ON temp.maxi = e.salary
    AND temp.departmentId = e.departmentId    
INNER JOIN 
    department as d ON
    d.id = temp.departmentId;
```

```sql
# using sub queries / corelated queries

SELECT D.Name AS Department ,E.Name AS Employee ,E.Salary 
FROM
	Employee E,
	(SELECT DepartmentId,max(Salary) as max FROM Employee GROUP BY DepartmentId) T,
	Department D
WHERE
    E.DepartmentId = T.DepartmentId AND E.Salary = T.maxAND E.DepartmentId = D.id
``` 

## [180. Consecutive Numbers](https://leetcode.com/problems/consecutive-numbers/)
> Write an SQL query to find all numbers that appear at least three times consecutively. Return the result table in any order. The query result format is in the following example. 

<details>
<summary>Schema</summary>

```sql

Table: Logs

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| num         | varchar |
+-------------+---------+
id is the primary key for this table.
id is an autoincrement column.

```
</details>

<code >Query</code>

```sql
--  leadwill give next leading value 
with cte as (
    select num,
    lead(num,1) over() next,
    lead(num,2) over() next2next
    from logs

)

select distinct num ConsecutiveNums from cte where (num=next) and (num=next2next)
``` 
</br>
</br>


 # Day 4
## [197. Rising Temperature](https://leetcode.com/problems/rising-temperature/)
> Problem 
<details>
<summary>Schema</summary>

```text

Table: Weather

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| recordDate    | date    |
| temperature   | int     |
+---------------+---------+
id is the primary key for this table.
This table contains information about the temperature on a certain day.


```
</details>
<code >Query</code>

```sql

-- WE have two function DATE_ADD for increasing date and DATE_SUB decresing date 
SELECT w1.id
FROM Weather w1
JOIN Weather w2 ON w1.recordDate = DATE_ADD(w2.recordDate, INTERVAL 1 DAY)
WHERE w1.temperature > w2.temperature


``` 

## [196. Delete Duplicate Emails](https://leetcode.com/problems/delete-duplicate-emails/)
> Problem 
<details>
<summary>Schema</summary>

```text

Table: Person

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id is the primary key column for this table.
Each row of this table contains an email. The emails will not contain uppercase letters.

```
</details>
<code >Query</code>

```sql

-- Brute Force approach getting all id whic are not same then removing it
DELETE p
FROM Person p
INNER JOIN (
  SELECT p1.id
  FROM Person p1
  INNER JOIN Person p2 ON p1.email = p2.email AND p1.id > p2.id
) AS temp_ids ON p.id = temp_ids.id;


-- better approach
DELETE p1
FROM Person as p1 LEFT JOIN Person as p2 ON p1.email = p2.email
WHERE p2.id < p1.id



-- optimal approach 
DELETE 
From person 
Where id NOT IN (
  SELECT minId  from (
    SELECT email , min(id) as minId from Person  GROUP BY email having id = minId) as temp
  );

``` 


 <!-- # Day 5
## [Question ]()
> Problem 
<details>
<summary>Schema</summary>

```text
schema
```
</details>
<code >Query</code>

```sql
query
```  -->