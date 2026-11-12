// The assistant of the ONELAB web app: a model of a provider (OpenAI for
// now), asked from the page with the user's own key. The key is kept here, in
// memory (gone with the page), and in the storage of the browser only if the
// user asks for it; it is sent only to the provider, in the header of its
// requests: never to Gmsh (its options, the script, the ONELAB database), to
// the solver's worker, or to the messages.

const providers = {
  openai: {name: 'OpenAI', models: 'https://api.openai.com/v1/models',
           responses: 'https://api.openai.com/v1/responses'},
};

// what the browser keeps (the key only if asked)
const stored = {provider: 'assistantProvider', model: 'assistantModel',
                key: 'assistantKey'};
const load = (name) => { try { return localStorage.getItem(name); } catch(e) { return null; } };
const save = (name, value) => {
  try {
    if(value) localStorage.setItem(name, value);
    else localStorage.removeItem(name);
  } catch(e) {}
};

let provider = load(stored.provider) || 'openai';
let model = load(stored.model) || '';
let key = load(stored.key) || '';

// The error of the answer r of a provider (its message if it gives one)
function failure(name, r, body) {
  const why = (body && body.error && body.error.message) || r.statusText;
  if(r.status === 401) return `Key refused by ${providers[name].name}: ${why}`;
  return `${providers[name].name} answered ${r.status}: ${why}`;
}

// The models of a provider the key gives, sorted: {models} or {error}
async function listModels(name, k) {
  let r;
  try {
    r = await fetch(providers[name].models, {headers: {Authorization: 'Bearer ' + k}});
  }
  catch(e) {
    return {error: `No answer from ${providers[name].name} (network?)`};
  }
  let body = null;
  try { body = await r.json(); } catch(e) {}
  if(!r.ok) return {error: failure(name, r, body)};
  const models = ((body && body.data) || []).map((m) => m.id).sort();
  return {models};
}

// The dialog of the key (see #keyDialog in onelab.html), shown by show()
export function installKeyDialog(setStatus) {
  const $ = (id) => document.getElementById(id);
  const dialog = $('keyDialog'), text = $('keyText'), remember = $('keyRemember'),
        models = $('keyModel'), note = $('keyStatus'), select = $('keyProvider');
  for(const [name, p] of Object.entries(providers))
    select.add(new Option(p.name, name));
  const tell = (t, error = false) => {
    note.textContent = t;
    note.classList.toggle('error', error);
  };
  // the models in the list, the one chosen kept if it is there
  const fill = (list, chosen) => {
    models.replaceChildren(...list.map((m) => new Option(m, m)));
    if(chosen && !list.includes(chosen)) models.add(new Option(chosen, chosen), 0);
    models.value = chosen || list[0] || '';
  };
  $('keyTest').addEventListener('click', async () => {
    const k = text.value.trim();
    if(!k) return tell('No key to test', true);
    tell('Asking ' + providers[select.value].name + '...');
    const r = await listModels(select.value, k);
    if(r.error) return tell(r.error, true);
    fill(r.models, models.value);
    tell(`Key accepted: ${r.models.length} models`);
  });
  $('keyForget').addEventListener('click', () => {
    key = '';
    save(stored.key, '');
    text.value = '';
    remember.checked = false;
    tell('Key forgotten');
    setStatus('Assistant key forgotten');
  });
  dialog.addEventListener('close', () => {
    if(dialog.returnValue !== 'save') return;
    provider = select.value;
    model = models.value;
    key = text.value.trim();
    save(stored.provider, provider);
    save(stored.model, model);
    save(stored.key, remember.checked ? key : '');
    setStatus(key ? `Assistant key set (${providers[provider].name}` +
              (model ? ', ' + model : '') + (remember.checked ? ', remembered' : '') + ')' :
              'No assistant key');
  });
  return function show() {
    select.value = provider;
    text.value = key;
    remember.checked = !!load(stored.key);
    fill(model ? [model] : [], model);
    tell('');
    dialog.showModal();
  };
}

// What the model is told of its job (the tools say what each does)
const instructions = `You are the assistant of the web app of Gmsh, the finite \
element mesh generator, working for its user on the model open in the page. \
You act on the model only through your tools.
- Geometry, physical groups, meshing constraints and options are commands of \
Gmsh's .geo language, added to the script of the model with add_geo. The \
commands of one call are read together: if they have an error, none of them \
is added and the errors are returned; correct them and call again.
- Call get_model_state before changing a model you have not seen, and after \
changes whose tags you need: it gives the script, the entities, the physical \
groups, the mesh, and the geometry kernels Gmsh has here. The last \
SetFactory of the script applies: if OpenCASCADE is not available, set \
SetFactory("Built-in") first and build with points, lines, curve loops, \
surfaces and extrusions.
- Never use SystemCall or Exit.
- Answer in the language of the user, briefly: say what you changed in the \
model, and what failed.`;

// The panel of the assistant (see #assistantTab in onelab.html): the
// conversation, and the tools of the page, [{name, description, parameters
// (a JSON schema), instructions (what the model is told of them besides, if
// anything), run(arguments): a result, an object}], those added to it later
// given from the next request on; keyDialog shows the dialog of the key
export function installAssistant(tools, keyDialog) {
  const $ = (id) => document.getElementById(id);
  const list = $('assistantMessages'), input = $('assistantInput'),
        send = $('assistantSend');
  // the conversation, as the provider has it (the items of its answers
  // given back as they are), and the request under way
  let history = [], controller = null;
  // a message of the conversation (kind: user, assistant, tool, note or
  // error), its text never read as HTML
  const show = (kind, text, code = '') => {
    const d = document.createElement('div');
    d.className = 'msg ' + kind;
    d.textContent = text;
    if(code) {
      const pre = document.createElement('pre');
      pre.textContent = code;
      d.append(pre);
    }
    list.append(d);
    list.scrollTop = list.scrollHeight;
  };
  // an answer of the model to the conversation so far
  async function respond(signal) {
    const schemas = tools.map(({name, description, parameters}) =>
      ({type: 'function', name, description, parameters, strict: true}));
    const guidance = [instructions, ...tools.map((t) => t.instructions).filter(Boolean)];
    const r = await fetch(providers[provider].responses, {
      method: 'POST', signal,
      headers: {'Content-Type': 'application/json', Authorization: 'Bearer ' + key},
      body: JSON.stringify({model, instructions: guidance.join('\n'), input: history,
                            tools: schemas}),
    });
    let body = null;
    try { body = await r.json(); } catch(e) {}
    if(!r.ok) throw new Error(failure(provider, r, body));
    return body;
  }
  // what a tool did, as the conversation shows it (its commands, or its
  // arguments given)
  const told = (call, args, result) => {
    const failed = result.error || result.added === false;
    const what = call.name.replace(/_/g, ' ') + (failed ? ': ' + (result.error || 'not added') : '');
    show(failed ? 'tool failed' : 'tool', what, args.commands ||
         Object.entries(args).filter(([k, v]) => v !== null && v !== '')
           .map(([k, v]) => k + ': ' + v).join('\n'));
  };
  async function ask(text) {
    if(!key || !model) {
      keyDialog();
      return;
    }
    show('user', text);
    history.push({role: 'user', content: text});
    controller = new AbortController();
    send.textContent = 'Stop';
    try {
      // (the rounds of tools, a bound for a model that would not stop)
      for(let round = 0; round < 30; round++) {
        const answer = await respond(controller.signal);
        const output = answer.output || [];
        history.push(...output);
        for(const item of output) {
          if(item.type !== 'message') continue;
          for(const c of item.content || []) {
            if(c.type === 'output_text') show('assistant', c.text);
            else if(c.type === 'refusal') show('error', c.refusal);
          }
        }
        const calls = output.filter((item) => item.type === 'function_call');
        if(!calls.length) {
          if(answer.status === 'incomplete')
            show('error', 'Answer cut short' + (answer.incomplete_details ?
              ' (' + answer.incomplete_details.reason + ')' : ''));
          break;
        }
        for(const call of calls) {
          const tool = tools.find((t) => t.name === call.name);
          let args = {}, result;
          try {
            args = JSON.parse(call.arguments || '{}');
            result = tool ? await tool.run(args) : {error: 'No tool ' + call.name};
          }
          catch(e) {
            result = {error: e.message};
          }
          told(call, args, result);
          history.push({type: 'function_call_output', call_id: call.call_id,
                        output: JSON.stringify(result)});
        }
        if(round === 29) show('error', 'Stopped after 30 rounds of tools');
      }
    }
    catch(e) {
      show(e.name === 'AbortError' ? 'note' : 'error',
           e.name === 'AbortError' ? 'Stopped' : e.message);
    }
    controller = null;
    send.textContent = 'Send';
  }
  const go = () => {
    if(controller) {
      controller.abort();
      return;
    }
    const text = input.value.trim();
    if(!text) return;
    input.value = '';
    ask(text);
  };
  send.addEventListener('click', go);
  input.addEventListener('keydown', (e) => {
    if(e.key === 'Enter' && !e.shiftKey) {
      e.preventDefault();
      go();
    }
  });
  $('assistantNew').addEventListener('click', () => {
    if(controller) controller.abort();
    history = [];
    list.replaceChildren();
  });
  $('assistantKey').addEventListener('click', () => keyDialog());
}
