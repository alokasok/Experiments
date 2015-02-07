from bs4 import BeautifulSoup
from urlparse import urlparse
from urlparse import urljoin
#import urlparse
import urllib
import requests
import os

url = raw_input("Enter the website:")
r = requests.get(url)
data = r.text
soup = BeautifulSoup(data)
out_folder =os.getcwd()
for link in soup.find_all('a'):
	print(link.get('href'))
	# '''
	pdf_url = urljoin(url,link.get('href'))
	print pdf_url
	filename = pdf_url.split("/")[-1]
	print filename
	outpath = os.path.join(out_folder, filename)
	print outpath
	#pdf = urllib.urlopen(link.get('href'))
	#print pdf
	urllib.urlretrieve(pdf_url, outpath)

	# '''
