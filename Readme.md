reproduce a weird acpp/python issue where redirecting stdout crashes acpp

```
python3 -m venv .venv                        
source .venv/bin/activate
export ACPP_PATH= <path to acpp binary>
pip install --verbose -e .
```
