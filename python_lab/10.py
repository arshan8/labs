from bs4 import BeautifulSoup
import requests

page = requests.get('https://en.wikipedia.org/wiki/Sachin_Tendulkar')

soup = BeautifulSoup(page.text,'html.parser')

images = soup.select('img')

for img in images:
    img_link = img.get('src')
    print(img_link)


