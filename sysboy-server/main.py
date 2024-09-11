import argparse
import asyncio
import json

from websockets.asyncio.server import serve


def load_config(config_file):
    with open(config_file, "r") as file:
        json_data = json.load(file)
    return json_data


async def handler(websocket):
    print("New client")
    async for message in websocket:
        event = json.loads(message)
        if event["command"] == "infos":
            print("command infos received")
            event = {
                "vram": 12,
                "cpu": 35,
            }
            await websocket.send(json.dumps(event))
        else:
            print("command '" + event["command"] + "' not supported")
            event = {"error": "command not yet implemented"}
            await websocket.send(json.dumps(event))


async def main(config=None):
    host = config.get("host")
    port = config.get("port")

    async with serve(handler, host, port):
        await asyncio.get_running_loop().create_future()


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--config", default="config.json", help="Path to JSON config file in the configs folder")
    args = parser.parse_args()
    config = load_config(args.config)

    asyncio.run(main(config))
