from bs4 import BeautifulSoup
import urllib2
import pickle

data = {}
def processCredits(__credits,title):
    tempdict = {}
    for i in __credits.findAll('a'):
        tempdict[i.getText()] = i.get('href')
    data[title]["credits"] = tempdict 
##Get The Movies from IMDB based on year
def getMovies(year):
    start = 1
    try:
        url = "http://www.imdb.com/search/title?sort=moviemeter,asc&start=%(start)s&title_type=feature&year=%(year)s" %{"start":start,"year":year}
        a = urllib2.urlopen(url)    
        resp = a.read()    
        soup = BeautifulSoup(resp)
        a = soup.find("table",{"class":"results"})
        a = soup.find("div",{"id":"left"}).getText()    
        it = int(a.split()[2].replace(',',''))
        print it
    except:
        print data
        return -1    
    while True:
        print "In URL :: " + url
        start+=50   
        #  For getting the title link : "http://imdb.com"+i.find('a').get('href')
        #  For getting the title : i.find('a').get('title')
        #  For getting the rating : i.findAll('span',{"class","value"})[0].getText()
        #  Desc : i.findAll('span',{"class","outline"})[0].getText()
        #  Genre : i.findAll('span',{"class","genre"})[0].getText()
        #  RunTime : i.findAll('span',{"class","runtime"})[0].getText()
        #  need to process the credits for extracting into dictionary
        for i in soup.findAll("tr",{"class":"even detailed"}):
            tempdict = {}
            try:
                title = i.find('a').get('title') 
                tempdict["link"] = "http://imdb.com"+i.find('a').get('href')
                tempdict["rating"] = i.findAll('span',{"class","value"})[0].getText()
                tempdict["desc"] = i.findAll('span',{"class","outline"})[0].getText()
                tempdict["genre"] = i.findAll('span',{"class","genre"})[0].getText().split('|')
                data[title] = tempdict
                processCredits(i.findAll('span',{"class","credit"})[0],title)
                tempdict["runtime"] = i.findAll('span',{"class","runtime"})[0].getText().split(" ")[0]
            except:
                print tempdict
                continue
             
        for i in soup.findAll("tr",{"class":"odd detailed"}):
            tempdict = {}
            try:
                title = i.find('a').get('title') 
                tempdict["link"] = "http://imdb.com"+i.find('a').get('href')
                tempdict["rating"] = i.findAll('span',{"class","value"})[0].getText()
                tempdict["desc"] = i.findAll('span',{"class","outline"})[0].getText()
                tempdict["genre"] = i.findAll('span',{"class","genre"})[0].getText().split('|')
                data[title] = tempdict
                processCredits(i.findAll('span',{"class","credit"})[0],title)
                tempdict["runtime"] = i.findAll('span',{"class","runtime"})[0].getText().split(" ")[0]
            except:
                print tempdict
                continue
        
        
        if start > it:
            break
        
        try:        
            url = "http://www.imdb.com/search/title?sort=moviemeter,asc&start=%(start)s&title_type=feature&year=%(year)s" %{"start":start,"year":year}
            a = urllib2.urlopen(url)    
            resp = a.read()    
            soup = BeautifulSoup(resp)
        except:
            return -1
def test():
    pkl_file = open('myfile.pkl', 'r')
    mydict2 = pickle.load(pkl_file)
    pkl_file.close()
    
    print len(mydict2)






test()