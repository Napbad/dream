import yaml


CONFIG_FILE_PATH = "../../config.yml"

def parse_config():
    with open(CONFIG_FILE_PATH, 'r', encoding='utf-8') as file:
        config_data = yaml.safe_load(file)
    return config_data

def print_config(config_data):
    print("Config:", config_data)


config = parse_config()
