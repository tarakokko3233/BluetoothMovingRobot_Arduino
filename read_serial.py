import serial
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# マイコンの初期位置とサイズ
microcontroller_position = [15, 15]
microcontroller_size = 3

# 障害物の位置のリスト
obstacle_positions = []

# 障害物の正方形のサイズ
obstacle_size = 1

IR_THRESHOLD = 60

# Matplotlibの設定
fig, ax = plt.subplots()
ax.set_xlim(0, 30)
ax.set_ylim(0, 100)

# シリアル通信の初期化
ser = serial.Serial("/dev/cu.HC-06", 9600)

def update(frame):
    global obstacle_positions, microcontroller_position

    if ser.in_waiting:
        line = ser.readline().decode('utf-8').rstrip()
        print(line)
        leftIR, rightIR = map(int, line.split(','))

        if leftIR > IR_THRESHOLD and rightIR > IR_THRESHOLD:
            # 左右両方のIRセンサが25を超えた場合、新たな障害物を追加せず、動きも止める
            pass
        elif leftIR > IR_THRESHOLD:
            # 左のIRセンサが25を超えた場合、マイコンを右に移動し、障害物を追加
            microcontroller_position[0] += 1
            obstacle_positions.append([microcontroller_position[0] - 3, microcontroller_position[1] + 2])
        elif rightIR > IR_THRESHOLD:
            # 右のIRセンサが25を超えた場合、マイコンを左に移動し、障害物を追加
            microcontroller_position[0] -= 1
            obstacle_positions.append([microcontroller_position[0] + 3, microcontroller_position[1] + 2])
        else:
            # 既存の障害物位置を更新（下に移動）
            obstacle_positions = [[x, y - 2] for x, y in obstacle_positions if y > 0]

        # 画面をクリアして再描画
        ax.clear()
        ax.set_xlim(0, 30)
        ax.set_ylim(0, 30)

        # マイコン（正方形）と障害物（赤の正方形）の位置をプロット
        ax.add_patch(plt.Rectangle((microcontroller_position[0] - microcontroller_size / 2,
                                    microcontroller_position[1] - microcontroller_size / 2),
                                   microcontroller_size, microcontroller_size, color="blue"))
        for pos in obstacle_positions:
            ax.add_patch(plt.Rectangle((pos[0] - obstacle_size / 2, pos[1] - obstacle_size / 2),
                                       obstacle_size, obstacle_size, color="red"))

# アニメーションの開始
ani = animation.FuncAnimation(fig, update, frames=1000, cache_frame_data=False, blit=False)
plt.show()
