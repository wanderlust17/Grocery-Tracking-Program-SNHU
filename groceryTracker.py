import itertools

print("A grocery tracker software")
"""
A grocery tracking software that creates frequency tables
of the purchase of items collected

Algorithm:
    - First collect the data from the input file
    - Create a frequency tables of each item 
    - And the times at which they are received
    - Sort the items based on the order
"""

def get_content(file):
    with open(file, "r") as f:
        lines = f.readlines()
    preprocessed_items=[]
    for l in lines:
        as_list=l.split(" ")
        preprocessed_items.append(as_list)
    items_ = list(itertools.chain(*preprocessed_items))
    items = []
    for sub in items_:
        items.append(sub.replace("\n", ""))
    
    return items


def generateFrequencyTable(data):
    countdict = {}

    for item in data:
        if item in countdict:
            countdict[item] = countdict[item] + 1
        else:
            countdict[item] = 1
    itemlist = list(countdict.keys())
    itemlist.sort()

    print("ITEM", "FREQUENCY")

    for item in itemlist:
        print(item, "   ", countdict[item])

   
    return countdict


if __name__ == "__main__":
    data=get_content('text_input.txt')
    generateFrequencyTable(data)
    print("End of grocery tracker program")
