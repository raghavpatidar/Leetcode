# Daily SQL problem June .

- [Daily SQL problem June .](#daily-sql-problem-june-)
- [Day 1](#day-1)
  - [175.  Combine Two Tables](#175--combine-two-tables)
  - [181. Employees Earning More Than Their Managers](#181-employees-earning-more-than-their-managers)



# Day 1
## [175.  Combine Two Tables](https://leetcode.com/problems/combine-two-tables/) 
<h4> Write an SQL query to report the first name, last name, city, and state of each person in the <code>Person</code> table. If the address of a personId is not present in the <code>Address</code>  table, report null instead.
</h4>
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



## [181. Employees Earning More Than Their Managers](https://leetcode.com/problems/employees-earning-more-than-their-managers/)
<h4>Write an SQL query to find the employees who earn more than their managers.
Return the result table in any order.The query result format is in the following example.</h4>
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


<!-- ## [Question name]()
<h4> Problem statement
# Day 2
## [182. Duplicate Emails](https://leetcode.com/problems/duplicate-emails/description/)
<h4>Write an SQL query to report all the duplicate emails. Note that it's guaranteed that the email field is not NULL.
Return the result table in any order.
The query result format is in the following example.
</h4>
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
</h4>
<details>
<summary>Schema</summary>

```text
schema
```
</details>

<code >Query</code>
```sql
query
``` -->
