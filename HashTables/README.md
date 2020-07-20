<p style="align: center;"><h1>Hash Tables</h1></p>
<p><h4>What is a hash table?</h4></p>
A hash table is an effective data structure for implementing dictionaries. Under reasonable assumptions, the average time to search for an element in a hash table is O(1).

A hash table generalizes the simpler notion of an ordinary array. Directly addressing into an ordinary array makes effective use of our ability to examine an arbitrary position in an array in O(1) time.

<p><h4>Hash Function</h4></p>
A function that manipulates the key to produce an array index.
<p align="center">
  <img width="460" height="400" src="img/hashTable.JPG" style="border-radius: 10px;">
</p><br>
<p><h4>What makes a good hash function?</h4></p>
A good hash function minimizes collisions, but they’re impossible to completely avoid.
<br>
<p><b>Collision:</b><span> When multiple keys produce the same hash location.</span></p>

```C++
//1. Returns an integer between 0 and MAX_ITEMS -1.
int ItemType::Hash() const
{
  return (id_num % MAX_ITEMS);
}

//2. Returns the element in the array at position item.Hash().
void ListType<ItemType>::GetItem(ItemType& i)
{
  int location;
  location = i.Hash();
  i = info[location];
}
```
<br>
<p><h4>Handling Collisions</h4></p>
<hr style="width: 50%;">
<p><h4>Linear Probing</h4></p>
Resolves hash collisions by searching for the next available space
If the end of the hash is reached, linear probing loops around to the beginning.

Deleting an item creates an empty spot
Linear probing will stop when it encounters the deleted second item’s slot, reporting that the third item does not exist.

<p><h4>Buckets and Chaining</h4></p>
Handle collisions by allowing multiple elements to have the same hash value

**Bucket** A collection of values associated with the same hash key; has limited space.

**Chain:** A linked list of elements that share the same hash key; the hash table has pointers to list of values.

<hr style="width: 50%;">

<p><h4>What's a Good Hash Function?</h4></p>
<ul>Efficiency: Hash tables have O(1) search. This deteriorates if the hash function is inefficient.</ul>
<ul>Simplicity: Don’t forget hash functions need to be written and maintained. Complex functions may incur a technical cost.</ul>
<ul>Perfect hash functions are difficult but not impossible, especially for small sets of values.</ul>

<p><h4> How to choose a good hash function</h4></p>
<ul>A good hash function reduces collisions by uniformly distributing elements</ul>
<ul>Knowledge about the domain of keys helps</ul>
<ul>Probing, buckets, and chaining can only do so much when there’s many collisions</ul>
