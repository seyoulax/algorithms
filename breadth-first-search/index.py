from collections import deque

#longest name is longers than 5 chars 

#make graph
graph = {}
graph["me"] = ["Vova", "Vasya", "Petya"]
graph["Vova"] = ["Seva", "Vlad"]
graph["Petya"] = ["John"]
graph["John"] = ["Kristian"]
graph["Vasya"] = []
graph["Kristian"] = []
graph["Seva"] = []
graph["Vlad"] = []

#function to define is current persons name is longer than 5 chars
def is_longest(current):
    if len(current) > 5:
        return True;
    return False 


#fastest way to find who has the longest name 
def search_longest_name(deque):
    deque = deque()
    deque += graph["me"]
    searched = []
    while deque:
        person = deque.popleft()
        if is_longest(person):
            print(person) 
            return True
        else:
            deque += graph[person]
            searched.append(person)
    return False

search_longest_name(deque)
