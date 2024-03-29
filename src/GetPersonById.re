let ste = ReasonReact.string;

/* alias Person as person because compiler doesn't like uppercase key names */
module GetPerson = [%graphql
  {|
    query getPerson ($id:ID!){
      person:
          Person(id:$id) {
            id
            age
            name
          }
        }
   |}
];

module GetPersonQuery = ReasonApollo.CreateQuery(GetPerson);

let component = ReasonReact.statelessComponent("Query");

let make = (~id, _children) => {
  ...component,
  render: _self => {
    let getPersonQuery = GetPerson.make(~id, ());
    <GetPersonQuery variables=getPersonQuery##variables>
      ...{({result}) =>
        <div>
          {switch (result) {
           | Error(e) =>
             Js.log(e);
             "Something Went Wrong" |> ste;
           | Loading => "Loading" |> ste
           | Data(response) =>
             switch (response##person) {
             | None => "No Person Data" |> ste
             | Some(person) => <div> {person##name |> ste} </div>
             }
           }}
        </div>
      }
    </GetPersonQuery>;
  },
};
