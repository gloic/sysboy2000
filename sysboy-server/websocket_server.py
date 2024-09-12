import asyncio

from websockets.asyncio.server import serve


class WebSocketServer:
    def __init__(self, config=None):
        self.config = config or {}
        self.host = self.config.get("host")
        self.port = self.config.get("port")

    async def serve(self, handler):
        async with serve(handler, self.host, self.port):
            await asyncio.get_running_loop().create_future()
