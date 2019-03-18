# Reproduce [an issue with refmt](https://github.com/facebook/reason/issues/2349) in bs-platform@5.0.0-dev.5
1. Clone this repo
2. Install dependencies
3. Run `yarn start`
4. Run `yarn format`
5. See the compile error
6. See that [this line](https://github.com/baldurh/repro-refmt-issue-bs-platform-5/blob/master/src/index.re#L25) is now incorrectly formatted.

# Reason-Apollo Swapi

This project illustrates the usage of reason-apollo to query the [SWAPI](http://swapi.apis.guru/) and serves as an example on how to use the project.

## Getting started

```
npm install
npm start
# in another tab
npm run webpack
```

After you see the webpack compilation succeed (the `npm run webpack` step), open up the nested html files in `src/*` (**no server needed!**). Then modify whichever file in `src` and refresh the page to see the changes.
