
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
