import json


class ConfigLoader:
    def __init__(self):
        pass

    def load(self, config_file=None):
        with open(config_file, "r") as file:
            json_data = json.load(file)
        return json_data
