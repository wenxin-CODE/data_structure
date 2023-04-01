import mne
import json

data_path = 'F:\\data\\edf\\1_0002.edf'   # 存放数据的具体位置，需要改成自己数据存放的地方
signal_name  = 'C3'     # 所选的通道名称
raw_data = mne.io.read_raw_edf(data_path, preload=False)   
# preload: 如果为True，则数据将被预加载到内存中(这样可以加快数据的索引), 默认为False
raw_data.pick_channels([signal_name])   
eeg = raw_data.to_data_frame()   # 将读取的数据转换成pandas的DataFrame数据格式
eeg = list(eeg.values[:,1])  #转换成numpy的特有数据格式
print(eeg)