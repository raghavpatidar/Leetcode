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
</br>
</br>

 # Day 5
## [577. Employee Bonus](https://leetcode.com/problems/employee-bonus/description/)
> Write an SQL query to report the name and bonus amount of each employee with a bonus less than 1000.
Return the result table in any order.
The query result format is in the following example. 

<details>
<summary>Schema</summary>

```text

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

```text


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

```text

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

```text


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

```text
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

```text

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

```text

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

```text

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

```text

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

```text

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

```text

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

```text

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
 


<!-- 

# Day 10

## [Question]()

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
```
</br>
 

 -->
