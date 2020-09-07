int ItemType::Hash() const
{
  return (id_num % MAX_ITEMS);
}

template<class ItemType>
void ListType<ItemType>::GetItem(ItemType& i)
{
  int location;
  location = i.Hash();
  i = info[location];
}

template<class ItemType>
void ListType<ItemType>::InsertItem(ItemType i)
{
  int location;
  location = i.Hash();
  info[location] = i;
  length++;
}

template<class ItemType>
void ListType<ItemType>::InsertItem(ItemType i)
{
  int location;
  location = i.Hash();
  while (info[location] != emptyItem)
    location = (location + 1) % MAX_ITEMS;
  info[location] = i;
  length++;
}

template<class ItemType>
void ListType<ItemType>::GetItem(ItemType& i, bool&
found)
{ 
  int location;
  int start_location;
  bool moreToSearch = true;
  start_location = i.Hash();
  location = start_location;
  do
  {
    if (info[location] == i || info[location] == emptyItem)
      moreToSearch = false;
    else
      location = (location + 1) % MAX_ITEMS;
  } while (location != start_location && moreToSearch);
  found = (info[location] == i);
  if (found)
    i = info[location];
}
