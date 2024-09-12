import nvidia_smi


class GpuNvidiaInfos:
    def __init__(self):
        try:
            nvidia_smi.nvmlInit()
            self.cpt = False
        except Exception:
            self.cpt = True
            print("cpt")
            print("Cannot get NVIDIA infos")

    def get_data(self):

        if self.cpt:
            return {
                "total": 0,
                "free": 0,
                "used": 0
            }

        handle = nvidia_smi.nvmlDeviceGetHandleByIndex(0)
        # card id 0 hardcoded here, there is also a call to get all available card ids, so we could iterate

        info = nvidia_smi.nvmlDeviceGetMemoryInfo(handle)

        # print("Total memory:", info.total)
        # print("Free memory:", info.free)
        # print("Used memory:", info.used)
        # result = {
        #     "total": info.total,
        #     "free": info.free,
        #     "used": info.used,
        # }
        result = info.used / 1000000000
        nvidia_smi.nvmlShutdown()
        return result
