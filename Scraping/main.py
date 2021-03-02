#Importing Beautifulsoup and Requests
from bs4 import BeautifulSoup
import requests


name = list()
links = list()
solution_links = list()
problems = list()
html_text = requests.get('https://www.codechef.com/problems/medium/').text
soup = BeautifulSoup(html_text, 'lxml')
table = soup.find('table', class_ = 'dataTable')
table_body = table.find('tbody')
trs = table_body.find_all('tr', class_ = 'problemrow')
for tr in trs:
    element = tr.find('div', class_ = 'problemname')
    link = tr.find('div', class_ = 'problemname').a['href']
    solution_link = 'https://www.codechef.com/status/'+link[10:]+'?sort_by=All&sorting_order=asc&language=11&status=15&handle=&Submit=GO'
    link = 'https://www.codechef.com/problems/'+link
    solution_links.append(solution_link)
    links.append(link)
    problems.append(element)
    

for problem in problems:
    problem_name = problem.find('b').text
    name.append(problem_name)
for number in range(len(name)):
    print(f'Name: {name[number]}\nLink: {links[number]}\nSolution Link: {solution_links[number]}\n')
