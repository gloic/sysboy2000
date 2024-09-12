import argparse
import asyncio
import json
import subprocess as sp

import psutil

from config_loader import ConfigLoader
from websocket_server import WebSocketServer
from infos.gpu_nvidia import GpuNvidiaInfos

def get_cpu_load():
    return psutil.cpu_percent()


def get_infos():
    gpu = GpuNvidiaInfos().get_data()
    # result = {
    #     "vram": gpu.get("used"),
    #     "cpu": get_cpu_load(),
    # }
    gpu = int(round(gpu, 0))
    print(gpu)
    return gpu

async def handler(websocket):
    print("New client")
    async for message in websocket:
        event = json.loads(message)
        if event["command"] == "infos" or True:
            print("command infos received")
            event = get_infos()
            await websocket.send(str(event))
        else:
            print("command '" + event["command"] + "' not supported")
            event = {"error": "command not yet implemented"}
            await websocket.send(json.dumps(event))


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--config", default="config.json", help="Path to JSON config file in the configs folder")
    return parser.parse_args()


if __name__ == "__main__":
    args = parse_args()
    config = ConfigLoader().load(args.config)

    server = WebSocketServer(config.get("websocket"))
    asyncio.run(server.serve(handler))
