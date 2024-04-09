import numpy as np
import matplotlib.pyplot as plt
import os

plt.rcParams['font.sans-serif'] = ['Microsoft JhengHei']
plt.rcParams['axes.unicode_minus'] = False

dataName = 'data.txt'
yMax = xMax = 100
yMin = xMin = -100

path = os.path.split(os.path.abspath(__file__))[0]
os.chdir(path=path)

def main():
    global xMax, xMin, yMax, yMin

    with open(f'{path}\{dataName}', encoding='utf-8', mode='r') as file_in:
        data = eval(file_in.readline())

    xMin = 0; xMax = len(data)-1
    yMin = min(data); yMax = max(data)

    ax = setFig('練習', '(Practice)')

    plt.text(0, data[0], 0, fontsize=12, rotation=0, verticalalignment='top')
    for i in range(1, xMax+1):
        ax.plot([i, i-1], [data[i], data[i-1]], 'r.-')
        plt.text(i, data[i], i, fontsize=12, rotation=0, verticalalignment='top')
    
    plt.show()

def setFig(title, suptitle):
    plt.style.use(['Solarize_Light2', 'bmh'])
    fig, ax = plt.subplots(1, 1)
    ax.axis([xMin-(xMax-xMin)*0.1, xMax+(xMax-xMin)*0.1, yMin-(yMax-yMin)*0.1, yMax+(yMax-yMin)*0.1])
    # ax.set_title('Convex Hull', fontsize=12)
    plt.suptitle(title, fontsize=20)
    plt.title(suptitle, fontsize=12)
    ax.set_xlabel('x')
    ax.set_ylabel('y')
    # plt.tight_layout(pad=2)
    return ax

main()