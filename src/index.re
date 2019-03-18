ReactDOMRe.renderToElementWithId(
  <ReasonApollo.Provider client=Client.instance>
    <Page />
    {
      let foo = true ? "foo" : "bar";
      <span> {ReasonReact.string(foo)} </span>;
    }
    {
      let _foo = "foo";
      <span>
        {
          let bar = "bar";
          <span> {ReasonReact.string(bar)} </span>;
        }
      </span>;
    }
    {if (true) {
       let foo = "foo";
       ReasonReact.string(foo);
     } else {
       let bar = "bar";
       ReasonReact.string(bar);
     }}
    {true
       ? {let foo = "foo"; // refmt removes the semicolon here
          <span> {ReasonReact.string(foo)} </span>}
       : <span> {ReasonReact.string("bar")} </span>}
  </ReasonApollo.Provider>,
  "index",
);
