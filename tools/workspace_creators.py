import json
import os

from pathlib import Path
from abc import ABC, abstractmethod

from problem_scrapers import UVaProblemScraper


class WorkspaceCreator(ABC):
    def __init__(self, url):
        self.problem_scraper = None
        self.base_path = Path(__file__).absolute().parent.parent
        self.url = url

    def create_workspace(self):
        self.create_directory()
        self.write_testcases()
        self.write_info_json()

    @abstractmethod
    def create_directory(self):
        pass

    @abstractmethod
    def write_testcases(self):
        pass

    @abstractmethod
    def write_info_json(self):
        pass


class NoWorkspaceCreator(WorkspaceCreator):
    def create_directory(self):
        pass

    def write_testcases(self):
        pass

    def write_info_json(self):
        pass


class UVaWorkspaceCreator(WorkspaceCreator):
    def __init__(self, url):
        super().__init__(url)
        self.problem_scraper = UVaProblemScraper(url)
        self.solutions_dir = self.base_path / "solutions"
        self.problem_dir = None

    def create_directory(self):
        problem_name = self.problem_scraper.get_problem_name()
        problem_name_split = problem_name.split()
        problem_name_split[0] = "0" * (5 - len(problem_name_split[0])) + problem_name_split[0]
        problem_dir = " ".join(problem_name_split)

        self.problem_dir = self.solutions_dir / problem_dir

        if not os.path.exists(self.problem_dir):
            os.mkdir(self.problem_dir)

    def write_testcases(self):
        pass

    def write_info_json(self):
        problem_name = self.problem_scraper.get_problem_name()
        number = problem_name.split()[0]
        name = problem_name[len(number) + 3:]
        id = "0" * (5 - len(number)) + number
        external_url = f"https://onlinejudge.org/external/{int(number) // 100}/{number}.pdf"

        info = {
            "Name": name,
            "ID": id,
            "Online Judge URL": self.url,
            "External URL": external_url
        }

        with open(self.problem_dir / "info.json", "w") as json_handle:
            json.dump(info, json_handle, indent=4)
