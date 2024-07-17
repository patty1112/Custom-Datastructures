
1. I implemented a linked list for all lists used

2. Using a linked list, I was able to abstract operations to the LinkedList.hpp file.
Each time I added to the list, I needed to loop until the last element. Also, I needed
to create a new linked list for each data type used (face, string, and vertex).

3. The data structure does effect reading the file, for linked lists you only have to
add a new node to the end after iterating through. For arrays, you need to make an array 
that is one element bigger than before and copy all elements and the new element.

4. I built the lists one element at a time as I read through the wavefront file.
I found it easier this way since the number of each type was updated as the nodes were added.

5. When validating the file, linked lists need to loop through the list for every element.
An array may have been a better choice for constant elemental access. Also, I made pointers
that point to pHead in the middle of some functions. For this reason, pHead needs to be public.
I could have used the at() getter, but I did not have time to change the structure.

6. Arrays are better once they contain the faces, commments, and vertices. They are able to get
values just by refrenceing the position in relation to the beginning.

7.When printing from the lists, I still had to loop through until the element desired. 
Even if I used the at() getter, it would find each element individually.

8. Arrays are again better for printing since they can access each element in constant time.
There is no resizing needed for printing or validating since all data is placed in the array.
