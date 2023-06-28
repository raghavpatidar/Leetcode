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
- [Day 5](#day-5)
  - [577. Employee Bonus](#577-employee-bonus)
  - [584. Find Customer Referee](#584-find-customer-referee)
- [Day 6](#day-6)
  - [586. Customer Placing the Largest Number of Orders](#586-customer-placing-the-largest-number-of-orders)
  - [595. Big Countries](#595-big-countries)
  - [596. Classes More Than 5 Students](#596-classes-more-than-5-students)
- [Day 7](#day-7)
  - [607. Sales Person](#607-sales-person)
  - [610. Triangle Judgement](#610-triangle-judgement)
- [Day 8](#day-8)
  - [627. Swap Salary](#627-swap-salary)
  - [620. Not Boring Movies](#620-not-boring-movies)
  - [619. Biggest Single Number](#619-biggest-single-number)
- [Day 9](#day-9)
  - [1050. Actors and Directors Who Cooperated At Least Three Times](#1050-actors-and-directors-who-cooperated-at-least-three-times)
  - [1068. Product Sales Analysis I](#1068-product-sales-analysis-i)
- [Day 10](#day-10)
  - [1075. Project Employees I](#1075-project-employees-i)
  - [1084. Sales Analysis III](#1084-sales-analysis-iii)
- [Day 11](#day-11)
  - [511. Game Play Analysis I](#511-game-play-analysis-i)
  - [1141. User Activity for the Past 30 Days I](#1141-user-activity-for-the-past-30-days-i)
- [Day 12](#day-12)
  - [1148. Article Views I](#1148-article-views-i)
  - [1179. Reformat Department Table](#1179-reformat-department-table)
- [Day 13](#day-13)
  - [1211. Queries Quality and Percentage](#1211-queries-quality-and-percentage)
  - [1251. Average Selling Price](#1251-average-selling-price)
- [Day 14](#day-14)
  - [570. Managers with at Least 5 Direct Reports](#570-managers-with-at-least-5-direct-reports)
  - [178. Rank Scores](#178-rank-scores)
- [Day 15](#day-15)
  - [608. Tree Node](#608-tree-node)
  - [585. Investments in 2016](#585-investments-in-2016)
- [Day 16](#day-16)
  - [550. Game Play Analysis IV](#550-game-play-analysis-iv)
  - [602. Friend Requests II: Who Has the Most Friends](#602-friend-requests-ii-who-has-the-most-friends)
- [Day 17](#day-17)
  - [1280. Students and Examinations](#1280-students-and-examinations)
  - [1327. List the Products Ordered in a Period](#1327-list-the-products-ordered-in-a-period)
- [Day 18](#day-18)
  - [1378. Replace Employee ID With The Unique Identifier](#1378-replace-employee-id-with-the-unique-identifier)
  - [1407. Top Travellers](#1407-top-travellers)
- [Day 19](#day-19)
  - [1484. Group Sold Products By The Date](#1484-group-sold-products-by-the-date)
  - [1517. Find Users With Valid E-Mails](#1517-find-users-with-valid-e-mails)
- [Day 20](#day-20)
  - [1527. Patients With a Condition](#1527-patients-with-a-condition)
  - [1581. Customer Who Visited but Did Not Make Any Transactions](#1581-customer-who-visited-but-did-not-make-any-transactions)
- [Day 21](#day-21)
  - [1587. Bank Account Summary II](#1587-bank-account-summary-ii)
  - [1633. Percentage of Users Attended a Contest](#1633-percentage-of-users-attended-a-contest)
- [Day 22](#day-22)
  - [1661. Average Time of Process per Machine](#1661-average-time-of-process-per-machine)
  - [1667. Fix Names in a Table](#1667-fix-names-in-a-table)


# Day 1
## [175. Combine Two Tables](https://leetcode.com/problems/combine-two-tables/) 
> Write an SQL query to report the first name, last name, city, and state of each person in the <code>Person</code> table. If the address of a personId is not present in the <code>Address</code>  table, report null instead.


<details><summary>Schema</summary>

```sql
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

```sql
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

```sql
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

```sql
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

```sql
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

```sql

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

```sql

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
</br>
</br>

 # Day 5
## [577. Employee Bonus](https://leetcode.com/problems/employee-bonus/description/)
> Write an SQL query to report the name and bonus amount of each employee with a bonus less than 1000.
Return the result table in any order.
The query result format is in the following example. 

<details>
<summary>Schema</summary>

```sql

Table: Employee

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| empId       | int     |
| name        | varchar |
| supervisor  | int     |
| salary      | int     |
+-------------+---------+
empId is the primary key column for this table.
Each row of this table indicates the name and the ID of an employee in addition to their salary and the id of their manager.
 

Table: Bonus

+-------------+------+
| Column Name | Type |
+-------------+------+
| empId       | int  |
| bonus       | int  |
+-------------+------+
empId is the primary key column for this table.
empId is a foreign key to empId from the Employee table.
Each row of this table contains the id of an employee and their respective bonus.


```
</details>
<code >Query</code>

```sql

SELECT e.name  , b.bonus 
FROM Employee e 
LEFT JOIN Bonus b 
  ON e.empId = b.empId 
WHERE 
  b.bonus  < 1000 or bonus IS null;



``` 


## [584. Find Customer Referee](https://leetcode.com/problems/find-customer-referee/description/)

> Write an SQL query to report the names of the customer that are not referred by the customer with id = 2.
Return the result table in any order.
The query result format is in the following example.

<details>
<summary>Schema</summary>

```sql


Table: Customer

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| referee_id  | int     |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the id of a customer, their name, and the id of the customer who referred them.


```
</details>
<code >Query</code>

```sql

-- Brute Force
SELECT c1.name
FROM Customer AS c1
LEFT JOIN Customer AS c2 ON c1.referee_id = c2.id
WHERE c2.id != 2 OR c2.id IS NULL;

-- Optimal
SELECT name 
FROM CUstomer 
WHERE referee_id != 2 or referee_id is null;

``` 

</br>
</br>


 # Day 6
## [586. Customer Placing the Largest Number of Orders](https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/description/)

> Write an SQL query to find the customer_number for the customer who has placed the largest number of orders.
The test cases are generated so that exactly one customer will have placed more orders than any other customer.
The query result format is in the following example. 


<details>
<summary>Schema</summary>

```sql

Table: Orders

+-----------------+----------+
| Column Name     | Type     |
+-----------------+----------+
| order_number    | int      |
| customer_number | int      |
+-----------------+----------+
order_number is the primary key for this table.
This table contains information about the order ID and the customer ID.
 

```
</details>
<code >Query</code>

```sql

-- Write your MySQL query statement below

-- using sub queries
SELECT temp.customer_number 
FROM (
    SELECT customer_number ,count(order_number) as cntorders
    FROM orders 
      GROUP BY customer_number
  ) temp  
WHERE temp.cntorders = (
  SELECT MAX(cntorders) 
  FROM (
      SELECT count(order_number) as cntorders
      FROM orders 
      GROUP BY customer_number
  ) subquery
);

-- using limit and order by
SELECT customer_number 
FROM orders 
  GROUP BY customer_number 
  ORDER BY count(customer_number) DESC LIMIT 1;



```
</br>
 

## [595. Big Countries](https://leetcode.com/problems/big-countries/description/)

>A country is big if:
>it has an area of at least three million (i.e., 3000000 km2), or
>it has a population of at least twenty-five million (i.e., 25000000).
> - Write an SQL query to report the name, population, and area of the big countries.
> - Return the result table in any order.
>The query result format is in the following example.

<details>
<summary>Schema</summary>

```sql


Table: World

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| name        | varchar |
| continent   | varchar |
| area        | int     |
| population  | int     |
| gdp         | bigint  |
+-------------+---------+
name is the primary key column for this table.
Each row of this table gives information about the name of a country, the continent to which it belongs, its area, the population, and its GDP value.

```
</details>
<code >Query</code>

```sql


SELECT name , population , area 
FROM WORLD
    WHERE area >= 3000000 OR population >= 25000000;

```
</br>
 

## [596. Classes More Than 5 Students](https://leetcode.com/problems/classes-more-than-5-students/description/)

> Write an SQL query to report all the classes that have at least five students.
Return the result table in any order.
The query result format is in the following example. 

<details>
<summary>Schema</summary>

```sql
Table: Courses

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| student     | varchar |
| class       | varchar |
+-------------+---------+
(student, class) is the primary key column for this table.
Each row of this table indicates the name of a student and the class in which they are enrolled.

```
</details>
<code >Query</code>

```sql

SELECT class
FROM COURSES
    GROUP BY class 
    HAVING count(*) >= 5; 

    
```
</br>
</br>
 
# Day 7
## [607. Sales Person](https://leetcode.com/problems/sales-person/description/)

> Write an SQL query to report the names of all the salespersons who did not have any orders related to the company with the name "RED".
Return the result table in any order.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

able: SalesPerson

+-----------------+---------+
| Column Name     | Type    |
+-----------------+---------+
| sales_id        | int     |
| name            | varchar |
| salary          | int     |
| commission_rate | int     |
| hire_date       | date    |
+-----------------+---------+
sales_id is the primary key column for this table.
Each row of this table indicates the name and the ID of a salesperson alongside their salary, commission rate, and hire date.
 

Table: Company

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| com_id      | int     |
| name        | varchar |
| city        | varchar |
+-------------+---------+
com_id is the primary key column for this table.
Each row of this table indicates the name and the ID of a company and the city in which the company is located.
 

Table: Orders

+-------------+------+
| Column Name | Type |
+-------------+------+
| order_id    | int  |
| order_date  | date |
| com_id      | int  |
| sales_id    | int  |
| amount      | int  |
+-------------+------+
order_id is the primary key column for this table.
com_id is a foreign key to com_id from the Company table.
sales_id is a foreign key to sales_id from the SalesPerson table.
Each row of this table contains information about one order. This includes the ID of the company, the ID of the salesperson, the date of the order, and the amount paid.
 

```
</details>
<code >Query</code>

```sql

SELECT s.name
FROM SalesPerson as s
WHERE 
s.sales_id not IN
(SELECT 
  o.sales_id as saleid
FROM 
  (SELECT com_id FROM Company WHERE name = "RED") temp
INNER JOIN 
  orders as o ON o.com_id = temp.com_id) 



```
</br>




## [610. Triangle Judgement](https://leetcode.com/problems/triangle-judgement/)

> Write an SQL query to report for every three line segments whether they can form a triangle.
Return the result table in any order.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

Table: Triangle

+-------------+------+
| Column Name | Type |
+-------------+------+
| x           | int  |
| y           | int  |
| z           | int  |
+-------------+------+
(x, y, z) is the primary key column for this table.
Each row of this table contains the lengths of three line segments.

```
</details>
<code >Query</code>

```sql

-- using If statement
SELECT *  , if( x < y + z and  y < x + z and z < x + y , "Yes" , "No") as triangle from Triangle;

-- using Case Statement
SELECT  x , y , z ,
CASE 
  WHEN  x < y + z and  y < x + z and z < x + y
  THEN  "Yes"
  ELSE "No" END as triangle
From Triangle

```
</br>
</br>



 # Day 8

 
## [627. Swap Salary](https://leetcode.com/problems/swap-salary/)
> Write an SQL query to swap all 'f' and 'm' values (i.e., change all 'f' values to 'm' and vice versa) with a single update statement and no intermediate temporary tables.
Note that you must write a single update statement, do not write any select statement for this problem.
The query result format is in the following example. 


<details>
<summary>Schema</summary>

```sql

Table: Salary

+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| id          | int      |
| name        | varchar  |
| sex         | ENUM     |
| salary      | int      |
+-------------+----------+
id is the primary key for this table.
The sex column is ENUM value of type ('m', 'f').
The table contains information about an employee.

```
</details>
<code >Query</code>

```sql


-- using If statement
UPDATE Salary 
Set sex = IF(sex = 'f' , 'm' , 'f');


-- using CASE
UPDATE Salary 
SET sex = CASE WHEN sex = 'f' then 'm' else 'f' END; 


```
</br>
 



## [620. Not Boring Movies](https://leetcode.com/problems/not-boring-movies/)

> Write an SQL query to report the movies with an odd-numbered ID and a description that is not "boring".
Return the result table ordered by rating in descending order.
The query result format is in the following example.

  

 
<details>
<summary>Schema</summary>

```sql

Table: Cinema

+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| id             | int      |
| movie          | varchar  |
| description    | varchar  |
| rating         | float    |
+----------------+----------+
id is the primary key for this table.
Each row contains information about the name of a movie, its genre, and its rating.
rating is a 2 decimal places float in the range [0, 10]

```
</details>
<code >Query</code>

```sql


SELECT * 
FROM Cinema 
Where id%2 = 1 AND description != "boring" 
ORDER BY rating DESC;

```
</br>
 



## [619. Biggest Single Number](https://leetcode.com/problems/biggest-single-number/)

> A single number is a number that appeared only once in the MyNumbers table.
Write an SQL query to report the largest single number. If there is no single number, report null.
The query result format is in the following example.

 
<details>
<summary>Schema</summary>

```sql

Table: MyNumbers

+-------------+------+
| Column Name | Type |
+-------------+------+
| num         | int  |
+-------------+------+
There is no primary key for this table. It may contain duplicates.
Each row of this table contains an integer.

```
</details>
<code >Query</code>

```sql

SELECT max(temp.num) as num
FROM(
  SELECT num FROM MyNumbers 
  GROUP BY num having count(num) = 1) temp;
  
```
</br>
</br>
 


# Day 9

## [1050. Actors and Directors Who Cooperated At Least Three Times](https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times/description/)

> Write a SQL query for a report that provides the pairs (actor_id, director_id) where the actor has cooperated with the director at least three times.
Return the result table in any order.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

Table: ActorDirector

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| actor_id    | int     |
| director_id | int     |
| timestamp   | int     |
+-------------+---------+
timestamp is the primary key column for this table.

```
</details>
<code >Query</code>

```sql

SELECT actor_id , director_id  
FROM ActorDirector 
GROUP BY actor_id , director_id 
HAVING count(director_id) > 2;

```
</br>

## [1068. Product Sales Analysis I](https://leetcode.com/problems/product-sales-analysis-i/description/)

> Write an SQL query that reports the product_name, year, and price for each sale_id in the Sales table.
Return the resulting table in any order.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

Table: Sales

+-------------+-------+
| Column Name | Type  |
+-------------+-------+
| sale_id     | int   |
| product_id  | int   |
| year        | int   |
| quantity    | int   |
| price       | int   |
+-------------+-------+
(sale_id, year) is the primary key of this table.
product_id is a foreign key to Product table.
Each row of this table shows a sale on the product product_id in a certain year.
Note that the price is per unit.
 

Table: Product

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| product_id   | int     |
| product_name | varchar |
+--------------+---------+
product_id is the primary key of this table.
Each row of this table indicates the product name of each product.


```
</details>
<code >Query</code>

```sql

SELECT p.product_name , s.year , s.price
FROM Product  p
INNER JOIN Sales s 
ON p.product_id = s.product_id

```
</br>
</br>
 



# Day 10

## [1075. Project Employees I](https://leetcode.com/problems/project-employees-i/)

> Write an SQL query that reports the average experience years of all the employees for each project, rounded to 2 digits.
Return the result table in any order.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

Table: Project

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| project_id  | int     |
| employee_id | int     |
+-------------+---------+
(project_id, employee_id) is the primary key of this table.
employee_id is a foreign key to Employee table.
Each row of this table indicates that the employee with employee_id is working on the project with project_id.
 

Table: Employee

+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| employee_id      | int     |
| name             | varchar |
| experience_years | int     |
+------------------+---------+
employee_id is the primary key of this table. It's guaranteed that experience_years is not NULL.
Each row of this table contains information about one employee.
 

```
</details>
<code >Query</code>

```sql



SELECT project.project_id,  ROUND(SUM(employee.experience_years)/COUNT(employee.employee_id),2) AS average_years
FROM employee
JOIN project ON project.employee_id = employee.employee_id
GROUP BY project.project_id;


-- inner join


SELECT 
    p.project_id,
    ROUND(AVG(e.experience_years), 2) AS average_years
FROM
    Project p 
    INNER JOIN Employee e ON e.employee_id = p.employee_id
GROUP BY p.project_id;



```
</br>
 






## [1084. Sales Analysis III](https://leetcode.com/problems/sales-analysis-iii/)

> Write an SQL query that reports the products that were only sold in the first quarter of 2019. That is, between 2019-01-01 and 2019-03-31 inclusive.
Return the result table in any order.
The query result format is in the following example 

 
<details>
<summary>Schema</summary>

```sql

Table: Product

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| product_id   | int     |
| product_name | varchar |
| unit_price   | int     |
+--------------+---------+
product_id is the primary key of this table.
Each row of this table indicates the name and the price of each product.
Table: Sales

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| seller_id   | int     |
| product_id  | int     |
| buyer_id    | int     |
| sale_date   | date    |
| quantity    | int     |
| price       | int     |
+-------------+---------+
This table has no primary key, it can have repeated rows.
product_id is a foreign key to the Product table.
Each row of this table contains some information about one sale.
 

```
</details>
<code >Query</code>

```sql

SELECT product_id , product_name
FROM 
    Product  
WHERE 
    product_id NOT IN 
        (
            SELECT product_id
            FROM Product
            LEFT JOIN Sales USING(product_id)
            WHERE sale_date < '2019-01-01' OR sale_date > '2019-03-31' OR sale_date IS Null
        )

```
</br>
</br>
 




# Day 11

## [511. Game Play Analysis I](https://leetcode.com/problems/game-play-analysis-i/)

> Write an SQL query to report the first login date for each player.
Return the result table in any order.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

Table: Activity

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| player_id    | int     |
| device_id    | int     |
| event_date   | date    |
| games_played | int     |
+--------------+---------+
(player_id, event_date) is the primary key of this table.
This table shows the activity of players of some games.
Each row is a record of a player who logged in and played a number of games (possibly 0) before logging out on someday using some device.

```
</details>
<code >Query</code>

```sql

SELECT player_id , min(event_date) AS first_login
FROM Activity
GROUP BY player_id

```
</br>
 

 

## [1141. User Activity for the Past 30 Days I](https://leetcode.com/problems/user-activity-for-the-past-30-days-i/description/)

> Write an SQL query to find the daily active user count for a period of 30 days ending 2019-07-27 inclusively. A user was active on someday if they made at least one activity on that day.
Return the result table in any order.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

Table: Activity

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| session_id    | int     |
| activity_date | date    |
| activity_type | enum    |
+---------------+---------+
There is no primary key for this table, it may have duplicate rows.
The activity_type column is an ENUM of type ('open_session', 'end_session', 'scroll_down', 'send_message').
The table shows the user activities for a social media website. 
Note that each session belongs to exactly one user.

```
</details>
<code >Query</code>

```sql

SELECT activity_date AS day , count(distinct user_id) AS active_users
FROM Activity  
GROUP BY activity_date
HAVING activity_date BETWEEN '2019-06-28' AND '2019-07-27'

```
</br>
</br>
 




# Day 12

## [1148. Article Views I](https://leetcode.com/problems/article-views-i/)

> Write an SQL query to find all the authors that viewed at least one of their own articles.
Return the result table sorted by id in ascending order.
The query result format is in the following example.

  

 
<details>
<summary>Schema</summary>

```sql

Table: Views

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| article_id    | int     |
| author_id     | int     |
| viewer_id     | int     |
| view_date     | date    |
+---------------+---------+
There is no primary key for this table, it may have duplicate rows.
Each row of this table indicates that some viewer viewed an article (written by some author) on some date. 
Note that equal author_id and viewer_id indicate the same person.

```
</details>
<code >Query</code>

```sql

SELECT distinct author_id as id 
FROM Views 
WHERE author_id = viewer_id 
ORDER BY id

```
</br>
 

## [1179. Reformat Department Table](https://leetcode.com/problems/reformat-department-table/)

> Write an SQL query to reformat the table such that there is a department id column and a revenue column for each month.
Return the result table in any order.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

Table: Department

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| revenue     | int     |
| month       | varchar |
+-------------+---------+
(id, month) is the primary key of this table.
The table has information about the revenue of each department per month.
The month has values in ["Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"].

```
</details>
<code >Query</code>

```sql


SELECT id,
SUM( IF ( month='Jan' , revenue , null )) AS Jan_Revenue,
SUM( IF ( month='Feb' , revenue , null )) AS Feb_Revenue,
SUM( IF ( month='Mar' , revenue , null )) AS Mar_Revenue,
SUM( IF ( month='Apr' , revenue , null )) AS Apr_Revenue,
SUM( IF ( month='May' , revenue , null )) AS May_Revenue,
SUM( IF ( month='Jun' , revenue , null )) AS Jun_Revenue,
SUM( IF ( month='Jul' , revenue , null )) AS Jul_Revenue,
SUM( IF ( month='Aug' , revenue , null )) AS Aug_Revenue,
SUM( IF ( month='Sep' , revenue , null )) AS Sep_Revenue,
SUM( IF ( month='Oct' , revenue , null )) AS Oct_Revenue,
SUM( IF ( month='Nov' , revenue , null )) AS Nov_Revenue,
SUM( IF ( month='Dec' , revenue , null )) AS Dec_Revenue
FROM Department
GROUP BY id;



```
</br>
</br>
 
# Day 13

## [1211. Queries Quality and Percentage](https://leetcode.com/problems/queries-quality-and-percentage/description/)

> We define query quality as:
> - The average of the ratio between query rating and its position
> We also define poor query percentage as:
> - The percentage of all queries with rating less than 3.
> Write an SQL query to find each query_name, the quality and poor_query_percentage.
> Both quality and poor_query_percentage should be rounded to 2 decimal places.
> Return the result table in any order.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

Table: Queries

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| query_name  | varchar |
| result      | varchar |
| position    | int     |
| rating      | int     |
+-------------+---------+
There is no primary key for this table, it may have duplicate rows.
This table contains information collected from some queries on a database.
The position column has a value from 1 to 500.
The rating column has a value from 1 to 5. Query with rating less than 3 is a poor query.

```
</details>
<code >Query</code>

```sql


SELECT 
  query_name , 
  ROUND((sum(rating/position)/count(*)),2) AS quality , 
  ROUND( AVG(rating<3)*100,2) AS poor_query_percentage 
FROM 
  Queries 
GROUP BY 
  query_name

```
</br>
 




## [1251. Average Selling Price](https://leetcode.com/problems/average-selling-price/description/)

> Write an SQL query to find the average selling price for each product. average_price should be rounded to 2 decimal places.
Return the result table in any order.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

Table: Prices

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| start_date    | date    |
| end_date      | date    |
| price         | int     |
+---------------+---------+
(product_id, start_date, end_date) is the primary key for this table.
Each row of this table indicates the price of the product_id in the period from start_date to end_date.
For each product_id there will be no two overlapping periods. That means there will be no two intersecting periods for the same product_id.
 

Table: UnitsSold

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| purchase_date | date    |
| units         | int     |
+---------------+---------+
There is no primary key for this table, it may contain duplicates.
Each row of this table indicates the date, units, and product_id of each product sold. 

```
</details>
<code >Query</code>

```sql

SELECT p.product_id , ROUND(SUM( u.units * p.price)/SUM(u.units) , 2) as average_price 
FROM Prices p 
INNER JOIN UnitsSold u
ON p.product_id = u.product_id
WHERE u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id

```
</br>
</br>
 





# Day 14


## [570. Managers with at Least 5 Direct Reports](https://leetcode.com/problems/managers-with-at-least-5-direct-reports/)

> Write an SQL query to report the managers with at least five direct reports.
Return the result table in any order.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

Table: Employee

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| department  | varchar |
| managerId   | int     |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the name of an employee, their department, and the id of their manager.
If managerId is null, then the employee does not have a manager.
No employee will be the manager of themself.

```
</details>
<code >Query</code>

```sql


SELECT e1.name
FROM employee e1
INNER JOIN employee e2
ON e1.id = e2.managerId
GROUP BY e1.name
HAVING count(e2.id)>=5;


```
</br>
</br>
 


## [178. Rank Scores](https://leetcode.com/problems/rank-scores/)

> Write an SQL query to rank the scores. The ranking should be calculated according to the following rules:
The scores should be ranked from the highest to the lowest.
If there is a tie between two scores, both should have the same ranking.
After a tie, the next ranking number should be the next consecutive integer value. In other words, there should be no holes between ranks.
Return the result table ordered by score in descending order.
The query result format is in the following example.

  

 
<details>
<summary>Schema</summary>

```sql

Table: Scores

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| score       | decimal |
+-------------+---------+
id is the primary key for this table.
Each row of this table contains the score of a game. Score is a floating point value with two decimal places.

```
</details>
<code >Query</code>

```sql

-- using count 
SELECT
  score,
  (SELECT COUNT(DISTINCT score)
   FROM scores s2
   WHERE s1.score <= s2.score) AS 'rank'
FROM scores s1
ORDER BY score DESC;



-- using dense rank
SELECT score, DENSE_RANK() OVER (ORDER BY score DESC) AS 'rank'
FROM Scores

```
</br>
</br>
 


# Day 15

## [608. Tree Node](https://leetcode.com/problems/tree-node/description/)

>  Each node in the tree can be one of three types:
> 
> - "Leaf": if the node is a leaf node.
> - "Root": if the node is the root of the tree.
> - "Inner": If the node is neither a leaf node nor a root node.
> Write an SQL query to report the type of each node in the tree.
> Return the result table in any order.
> The query result format is in the following example. 
> 
 
<details>
<summary>Schema</summary>

```sql

+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| p_id        | int  |
+-------------+------+
id is the primary key column for this table.
Each row of this table contains information about the id of a node and the id of its parent node in a tree.
The given structure is always a valid tree.

```
</details>
<code >Query</code>

```sql


SELECT id, 
(
  CASE WHEN p_id IS NULL THEN 'Root' 
  WHEN  id NOT in(select  p_id from Tree where p_id is not NULL) THEN "Leaf"
  ELSE "Inner" END 
) As type
FROM Tree

```
</br>

## [585. Investments in 2016](https://leetcode.com/problems/investments-in-2016/description/)

> Write an SQL query to report the sum of all total investment values in 2016 tiv_2016, for all policyholders who:
> - have the same tiv_2015 value as one or more other policyholders, and
> - are not located in the same city like any other policyholder (i.e., the (lat, lon) attribute pairs must be unique).
Round tiv_2016 to two decimal places.
> The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

Table: Insurance

+-------------+-------+
| Column Name | Type  |
+-------------+-------+
| pid         | int   |
| tiv_2015    | float |
| tiv_2016    | float |
| lat         | float |
| lon         | float |
+-------------+-------+
pid is the primary key column for this table.
Each row of this table contains information about one policy where:
pid is the policyholders policy ID.
tiv_2015 is the total investment value in 2015 and tiv_2016 is the total investment value in 2016.
lat is the latitude of the policy holder's city. It's guaranteed that lat is not NULL.
lon is the longitude of the policy holder's city. It's guaranteed that lon is not NULL.

```
</details>
<code >Query</code>

```sql


SELECT ROUND(SUM(tiv_2016),2) as tiv_2016
FROM insurance i1
WHERE tiv_2015 IN (
            SELECT tiv_2015 
            FROM insurance i2
            WHERE i1.pid != i2.pid)
AND (lat, lon) NOT IN (
            SELECT lat, lon 
            FROM insurance i3 
            WHERE i3.pid != i1.pid)



```
</br>
</br>
 


# Day 16

## [550. Game Play Analysis IV](https://leetcode.com/problems/game-play-analysis-iv/)

> Write an SQL query to report the fraction of players that logged in again on the day after the day they first logged in, rounded to 2 decimal places. In other words, you need to count the number of players that logged in for at least two consecutive days starting from their first login date, then divide that number by the total number of players.
The query result format is in the following example 

 
<details>
<summary>Schema</summary>

```sql

Table: Activity

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| player_id    | int     |
| device_id    | int     |
| event_date   | date    |
| games_played | int     |
+--------------+---------+
(player_id, event_date) is the primary key of this table.
This table shows the activity of players of some games.
Each row is a record of a player who logged in and played a number of games (possibly 0) before logging out on someday using some device.


```
</details>
<code >Query</code>

```sql


SELECT ROUND( count(distinct a.player_id)/( SELECT COUNT(DISTINCT player_id) AS cnt FROM activity ) , 2)as fraction
FROM Activity a
WHERE (player_id , DATE_SUB(event_date, INTERVAL 1 DAY))  IN (SELECT player_id, MIN(event_date) AS first_date FROM activity group by player_id ) 


```
</br>



## [602. Friend Requests II: Who Has the Most Friends](https://leetcode.com/problems/friend-requests-ii-who-has-the-most-friends/)

>  Write an SQL query to find the people who have the most friends and the most friends number.
The test cases are generated so that only one person has the most friends.
The query result format is in the following example.

 
<details>
<summary>Schema</summary>

```sql

Table: RequestAccepted

+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| requester_id   | int     |
| accepter_id    | int     |
| accept_date    | date    |
+----------------+---------+
(requester_id, accepter_id) is the primary key for this table.
This table contains the ID of the user who sent the request, the ID of the user who received the request, and the date when the request was accepted.

```
</details>
<code >Query</code>

```sql

select temp.id as id ,  count(temp.id) as num 
from (
select requester_id as id  from RequestAccepted
union all
select accepter_id as id from RequestAccepted) temp
Group by temp.id 
order by num desc limit 1

```
</br>
</br>
 
# Day 17

## [1280. Students and Examinations](https://leetcode.com/problems/students-and-examinations/)

> Write an SQL query to find the number of times each student attended each exam.
Return the result table ordered by student_id and subject_name.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

Table: Students

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| student_id    | int     |
| student_name  | varchar |
+---------------+---------+
student_id is the primary key for this table.
Each row of this table contains the ID and the name of one student in the school.
 

Table: Subjects

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| subject_name | varchar |
+--------------+---------+
subject_name is the primary key for this table.
Each row of this table contains the name of one subject in the school.
 

Table: Examinations

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| student_id   | int     |
| subject_name | varchar |
+--------------+---------+
There is no primary key for this table. It may contain duplicates.
Each student from the Students table takes every course from the Subjects table.
Each row of this table indicates that a student with ID student_id attended the exam of subject_name.
 

```
</details>
<code >Query</code>

```sql

# -- using only joins

SELECT
  s.student_id ,
  s.student_name ,
  sub.subject_name ,
  count(e.student_id) as attended_exams 
FROM 
  students s
INNER JOIN 
  subjects sub
LEFT JOIN 
  examinations e
ON 
  s.student_id = e.student_id
    AND
  sub.subject_name = e.subject_name
GROUP BY
  student_id , 
  subject_name
ORDER BY 
  student_id , 
  subject_name


-- using cte
with cte as (
    select * 
    FROM students st
    INNER JOIN subjects subs
    ORDER BY st.student_id , subs.subject_name
)

SELECT 
  cte.student_id as student_id ,  
  cte.student_name as student_name,
  cte.subject_name as subject_name,
  COUNT(e.student_id) as attended_exams 
FROM cte
LEFT JOIN 
  examinations e 
  ON e.student_id = cte.student_id AND e.subject_name = cte.subject_name
GROUP BY
  cte.student_id,
  cte.subject_name
order by 
  student_id,
  subject_name


```
</br>

## [1327. List the Products Ordered in a Period](https://leetcode.com/problems/list-the-products-ordered-in-a-period/)

> Write an SQL query to get the names of products that have at least 100 units ordered in February 2020 and their amount.
Return result table in any order.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

Table: Products

+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| product_id       | int     |
| product_name     | varchar |
| product_category | varchar |
+------------------+---------+
product_id is the primary key for this table.
This table contains data about the companys products.
 

Table: Orders

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| order_date    | date    |
| unit          | int     |
+---------------+---------+
There is no primary key for this table. It may have duplicate rows.
product_id is a foreign key to the Products table.
unit is the number of products ordered in order_date.
 

```
</details>
<code >Query</code>

```sql


SELECT p.product_name , sum(o.unit) as unit
FROM Products p
LEFT JOIN Orders o
ON p.product_id = o.product_id
where order_date >= '2020-02-01' and order_date <= '2020-02-29'
group by p.product_id
having sum(o.unit) >= 100


SELECT p.product_name , sum(o.unit) as unit
FROM Products p
LEFT JOIN Orders o
ON p.product_id = o.product_id
where MONTH(order_date) = 2 AND YEAR(order_date) = 2020
group by p.product_id
having sum(o.unit) >= 100

```
</br>
</br>
 
# Day 18

## [1378. Replace Employee ID With The Unique Identifier](https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/)

> Write an SQL query to show the unique ID of each user, If a user does not have a unique ID replace just show null.
Return the result table in any order.
The query result format is in the following example.

 
<details>
<summary>Schema</summary>

```sql

Table: Employees

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| name          | varchar |
+---------------+---------+
id is the primary key for this table.
Each row of this table contains the id and the name of an employee in a company.


Table: EmployeeUNI

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| unique_id     | int     |
+---------------+---------+
(id, unique_id) is the primary key for this table.
Each row of this table contains the id and the corresponding unique id of an employee in the company.


```
</details>
<code >Query</code>

```sql

SELECT eu.unique_id , e.name 
FROM employees e 
LEFT JOIN employeeUNI eu 
ON e.id = eu.id

```
</br>

## [1407. Top Travellers](https://leetcode.com/problems/top-travellers/)

> Write an SQL query to report the distance traveled by each user.
Return the result table ordered by travelled_distance in descending order, if two or more users traveled the same distance, order them by their name in ascending order.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

Table: Users

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| name          | varchar |
+---------------+---------+
id is the primary key for this table.
name is the name of the user.
 

Table: Rides

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| user_id       | int     |
| distance      | int     |
+---------------+---------+
id is the primary key for this table.
user_id is the id of the user who traveled the distance "distance".

```
</details>
<code >Query</code>

```sql


SELECT u.name , IFNULL(SUM(r.distance), 0) as travelled_distance
FROM users u
LEFT JOIN Rides r
ON u.id = r.user_id 
GROUP BY u.id
ORDER BY travelled_distance DESC , name





```
</br>
</br>
 
# Day 19

## [1484. Group Sold Products By The Date](https://leetcode.com/problems/group-sold-products-by-the-date/)

> Write an SQL query to find for each date the number of different products sold and their names.
The sold products names for each date should be sorted lexicographically.
Return the result table ordered by sell_date.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| sell_date   | date    |
| product     | varchar |
+-------------+---------+
There is no primary key for this table, it may contain duplicates.
Each row of this table contains the product name and the date it was sold in a market.

```
</details>
<code >Query</code>

```sql


SELECT 
  sell_date , 
  COUNT(distinct product) AS num_sold,
  GROUP_CONCAT(DISTINCT product ORDER BY product )  AS products
FROM 
  Activities 
GROUP BY 
  sell_date
ORDER BY 
  sell_date


```
</br>


## [1517. Find Users With Valid E-Mails](https://leetcode.com/problems/find-users-with-valid-e-mails/)

> Write an SQL query to find the users who have valid emails.
A valid e-mail has a prefix name and a domain where:
The prefix name is a string that may contain letters (upper or lower case), digits, underscore '_', period '.', and/or dash '-'. The prefix name must start with a letter.
The domain is '@leetcode.com'.
Return the result table in any order.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| name          | varchar |
| mail          | varchar |
+---------------+---------+
user_id is the primary key for this table.
This table contains information of the users signed up in a website. Some e-mails are invalid.

```
</details>
<code >Query</code>

```sql

SELECT *
FROM Users
WHERE REGEXP_LIKE(mail , '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode[.]com')

```
</br>
</br>
 
# Day 20

## [1527. Patients With a Condition](https://leetcode.com/problems/patients-with-a-condition/)

> Write an SQL query to report the patient_id, patient_name and conditions of the patients who have Type I Diabetes. Type I Diabetes always starts with DIAB1 prefix.
Return the result table in any order.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| patient_id   | int     |
| patient_name | varchar |
| conditions   | varchar |
+--------------+---------+
patient_id is the primary key for this table.
'conditions' contains 0 or more code separated by spaces. 
This table contains information of the patients in the hospital.

```
</details>
<code >Query</code>

```sql


select * from patients 
where conditions like 'DIAB1%' or conditions like '% DIAB1%';

```
</br>


## [1581. Customer Who Visited but Did Not Make Any Transactions](https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/)

>  Write a SQL query to find the IDs of the users who visited without making any transactions and the number of times they made these types of visits.
Return the result table sorted in any order.
The query result format is in the following example.

 
<details>
<summary>Schema</summary>

```sql

Table: Visits
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| visit_id    | int     |
| customer_id | int     |
+-------------+---------+
visit_id is the primary key for this table.
This table contains information about the customers who visited the mall.

Table: Transactions

+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| transaction_id | int     |
| visit_id       | int     |
| amount         | int     |
+----------------+---------+
transaction_id is the primary key for this table.
This table contains information about the transactions made during the visit_id.

```
</details>
<code >Query</code>

```sql

Select v.customer_id , count(v.customer_id) as count_no_trans 
from visits as v
where v.visit_id  not in( select t.visit_id from transactions as t)
group by v.customer_id 

```
</br>
</br>
 
# Day 21

## [1587. Bank Account Summary II](https://leetcode.com/problems/bank-account-summary-ii/)

> Write an SQL query to report the name and balance of users with a balance higher than 10000. The balance of an account is equal to the sum of the amounts of all transactions involving that account.
Return the result table in any order.
The query result format is in the following example 

 
<details>
<summary>Schema</summary>

```sql

SQL Schema
Table: Users

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| account      | int     |
| name         | varchar |
+--------------+---------+
account is the primary key for this table.
Each row of this table contains the account number of each user in the bank.
There will be no two users having the same name in the table.
 

Table: Transactions

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| trans_id      | int     |
| account       | int     |
| amount        | int     |
| transacted_on | date    |
+---------------+---------+
trans_id is the primary key for this table.
Each row of this table contains all changes made to all accounts.
amount is positive if the user received money and negative if they transferred money.
All accounts start with a balance of 0.

```
</details>
<code >Query</code>

```sql


select u.name as NAME, sum(t.amount) as BALANCE
from users u
inner join transactions t
on u.account = t.account
group by t.account 
having sum(t.amount) >10000

```
</br>


## [1633. Percentage of Users Attended a Contest](https://leetcode.com/problems/percentage-of-users-attended-a-contest/)

> Write an SQL query to find the percentage of the users registered in each contest rounded to two decimals.
Return the result table ordered by percentage in descending order. In case of a tie, order it by contest_id in ascending order.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

Table: Users

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| user_name   | varchar |
+-------------+---------+
user_id is the primary key for this table.
Each row of this table contains the name and the id of a user.
 

Table: Register

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| contest_id  | int     |
| user_id     | int     |
+-------------+---------+
(contest_id, user_id) is the primary key for this table.
Each row of this table contains the id of a user and the contest they registered into.

```
</details>
<code >Query</code>

```sql

select
  contest_id , 
  Round((count(user_id) / (select count(user_id) from users))*100 , 2) as percentage
from register
group by contest_id
order by percentage desc , contest_id 

```
</br>
</br>

# Day 22

## [1661. Average Time of Process per Machine](https://leetcode.com/problems/average-time-of-process-per-machine/)

> There is a factory website that has several machines each running the same number of processes. Write an SQL query to find the average time each machine takes to complete a process.
The time to complete a process is the 'end' timestamp minus the 'start' timestamp. The average time is calculated by the total time to complete every process on the machine divided by the number of processes that were run.
The resulting table should have the machine_id along with the average time as processing_time, which should be rounded to 3 decimal places.
Return the result table in any order.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

Table: Activity

+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| machine_id     | int     |
| process_id     | int     |
| activity_type  | enum    |
| timestamp      | float   |
+----------------+---------+
The table shows the user activities for a factory website.
(machine_id, process_id, activity_type) is the primary key of this table.
machine_id is the ID of a machine.
process_id is the ID of a process running on the machine with ID machine_id.
activity_type is an ENUM of type ('start', 'end').
timestamp is a float representing the current time in seconds.
'start' means the machine starts the process at the given timestamp and 'end' means the machine ends the process at the given timestamp.
The 'start' timestamp will always be before the 'end' timestamp for every (machine_id, process_id) pair

```
</details>
<code >Query</code>

```sql

with cte AS (
    select 
      a.machine_id  ,
      a.process_id  , 
      (a.timestamp - b.timestamp) as timediff
    from activity a
    inner join activity b
    on (
      a.machine_id = b.machine_id
        and 
      a.process_id = b.process_id 
        and 
      a.activity_type = 'end' 
        and 
      b.activity_type ='start')
)

select 
    machine_id , 
    ROUND(AVG(timediff),3) as processing_time 
from cte 
group by machine_id 

```
</br>


## [1667. Fix Names in a Table](https://leetcode.com/problems/fix-names-in-a-table/)

> Write an SQL query to fix the names so that only the first character is uppercase and the rest are lowercase.
Return the result table ordered by user_id.
The query result format is in the following example. 

 
<details>
<summary>Schema</summary>

```sql

Table: Users

+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| user_id        | int     |
| name           | varchar |
+----------------+---------+
user_id is the primary key for this table.
This table contains the ID and the name of the user. The name consists of only lowercase and uppercase characters.

```
</details>
<code >Query</code>

```sql


select 
  user_id,
  CONCAT(
        UPPER(LEFT(name , 1)),
        LOWER(RIGHT(name, LENGTH(name)-1))
      ) as name 
from users 
order by user_id

```
</br>
</br>
 
<!-- # Day 23

## [Question]()

> Problem 

 
<details>
<summary>Schema</summary>

```sql

schema

```
</details>
<code >Query</code>

```sql

query

```
</br>
</br>
  -->
