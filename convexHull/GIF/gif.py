import numpy as np
import matplotlib.pyplot as plt
import os
import imageio

plt.rcParams['font.sans-serif'] = ['Microsoft JhengHei']
plt.rcParams['axes.unicode_minus'] = False

path = os.path.split(os.path.abspath(__file__))[0]
inpuName = 'input.txt'
yMax = xMax = 100000
yMin = xMin = -100000
pointNum = 20
randInput = True

def main():
    global yMax, xMax, yMin, xMin
    os.chdir(path)

    if randInput:
        arr = list(randPoint())
    else:
        with open(f'{path}\\{inpuName}', encoding='utf-8', mode='r') as file_in:
            arr = [list(map(lambda x:float(x), data.strip('\n').split(' '))) for data in file_in.readlines()]
        xMax = yMax = -0x3f3f3f3f
        xMin = yMin = 0x3f3f3f3f
        for i in arr:
            xMax = i[0] if xMax < i[0] else xMax
            yMax = i[1] if yMax < i[1] else yMax
            xMin = i[0] if xMin > i[0] else xMin
            yMin = i[1] if yMin > i[1] else yMin
    arr.sort(key=lambda x: (x[0], x[1]))

    ax = setFig('凸包', '(Convex Hull)')
    for i in range(len(arr)):
        ax.plot(arr[i][0], arr[i][1], 'ko')
        # plt.text(arr[i][0]+(xMax-xMin)*0.1, arr[i][1], i+1, fontsize=12, rotation=0, verticalalignment = 'bottom')

    img = ConvexHullGif(arr, ax)

    gif(img, 'test3.gif', 2)
    for p in img:
        os.remove(f'{path}\{p}')
    
    plt.show()

def ConvexHullGif(arr, ax):
    data = []
    img = []
    pos = 0
    fig = []
    j = 0
    state = True
    for i in range(len(arr)):
        while pos >= 2 and cross(data[pos-2], data[pos-1], arr[i]) >= 0:
            if state:
                fig.append(ax.plot([data[pos-1][0], arr[i][0]], [data[pos-1][1], arr[i][1]], 'r.-')[0])
                plt.savefig(f'{j}.png')
                img.append(f'{j}.png')
                j += 1
            fig[-2].remove()
            fig[-1].remove()
            fig.pop(-2)
            fig.pop(-1)
            fig.append(ax.plot([data[pos-2][0], arr[i][0]], [data[pos-2][1], arr[i][1]], 'r.-')[0])
            plt.savefig(f'{j}.png')
            img.append(f'{j}.png')
            data.pop()
            pos -= 1
            j += 1
            state = False
        data.append(arr[i])
        if pos >= 1 and state:
            fig.append(ax.plot([data[pos-1][0], arr[i][0]], [data[pos-1][1], arr[i][1]], 'r.-')[0])
        elif state:
            fig.append(ax.plot([arr[0][0], arr[0][0]], [arr[0][1], arr[0][1]], 'r.-')[0])
        if state:
            plt.savefig(f'{j}.png')
            img.append(f'{j}.png')
            j += 1  
        pos += 1
        state = True

    newPos = pos-1
    for i in range(len(arr)-2, -1, -1):
        while pos >= newPos+2 and cross(data[pos-2], data[pos-1], arr[i]) >= 0:
            if state:
                fig.append(ax.plot([data[pos-1][0], arr[i][0]], [data[pos-1][1], arr[i][1]], 'g.-')[0])
                plt.savefig(f'{j}.png')
                img.append(f'{j}.png')
                j += 1
            fig[-2].remove()
            fig[-1].remove()
            fig.pop(-2)
            fig.pop(-1)
            fig.append(ax.plot([data[pos-2][0], arr[i][0]], [data[pos-2][1], arr[i][1]], 'g.-')[0])
            plt.savefig(f'{j}.png')
            img.append(f'{j}.png')
            data.pop()
            pos -= 1
            j += 1
            state = False
        data.append(arr[i])
        if pos >= 1 and state:
            fig.append(ax.plot([data[pos-1][0], arr[i][0]], [data[pos-1][1], arr[i][1]], 'g.-')[0])
        elif state:
            fig.append(ax.plot([arr[0][0], arr[0][0]], [arr[0][1], arr[0][1]], 'g.-')[0])
        if state:
            plt.savefig(f'{j}.png')
            img.append(f'{j}.png')
            j += 1  
        pos += 1
        state = True
    return img

def cross(org, p1, p2):
    return (p1[0]-org[0])*(p2[1]-org[1])-(p1[1]-org[1])*(p2[0]-org[0])

def randPoint():
    return np.random.uniform(xMin, xMax, [pointNum, 2])

def setFig(title, suptitle):
    plt.style.use(['Solarize_Light2', 'bmh'])
    fig, ax = plt.subplots(1, 1)
    ax.axis([xMin-(xMax-xMin)*0.1, xMax+(xMax-xMin)*0.1, yMin-(yMax-yMin)*0.1, yMax+(yMax-yMin)*0.1])
    plt.suptitle(title, fontsize=20)
    plt.title(suptitle, fontsize=12)
    ax.set_xlabel('x')
    ax.set_ylabel('y')

    return ax

def gif(imgName, expName, fps):
    gif_images = []
    for name in imgName:
        gif_images.append(imageio.v3.imread(f'{path}/{name}'))
    imageio.mimsave(expName, gif_images, fps=fps)

main()