import pytest
from src.flaskr.sample import f


def test_1():
    assert f() == 1
