# Problem Statement
You are the accountant of a big company and have been handed the task of maintaining a database of
salaries of all the people working in the company. Whenever a person joins or leaves the company,
you will need to update the database. Also, at times the manager may ask you for some statistics on
the data. Multiple employees could have the same salary. You need to design and implement a data
structure which supports the following operations (note 𝑥 and 𝑦 are positive integers) :

**𝑨(𝒙)**: Add salary 𝑥 to the database

𝑹(𝒙): Remove salary 𝑥 from the database if it exists, otherwise return the salary closest to 𝑥

𝑸(𝒙, 𝒚): Return the number of employees having salary in the range [𝑥, 𝑦]

Max: Return the maximum salary

Min: Return the minimum salary

If the current number of distinct salaries in the company is 𝑛, queries 𝐴, 𝑅,𝑄 should not take more
than 𝑂(𝑙𝑜𝑔 𝑛) time. All the salaries are integers in the range [1, 10<sup>6</sup>]. You should initialize the
database by reading salaries from a file. The first line of the file is an integer which specifies the
number of data points. Subsequent lines contain the salaries (one on each line).  
The test cases will consist of a sequence of the operations, A, R, Q, Max, Min and after each
operation you should report the relevant information.
