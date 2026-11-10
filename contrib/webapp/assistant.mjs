// The assistant of the ONELAB web app: a model of a provider (OpenAI for
// now), asked from the page with the user's own key. The key is kept here, in
// memory (gone with the page), and in the storage of the browser only if the
// user asks for it; it is sent only to the provider, in the header of its
// requests: never to Gmsh (its options, the script, the ONELAB database), to
// the solver's worker, or to the messages.

const providers = {
  openai: {name: 'OpenAI', models: 'https://api.openai.com/v1/models'},
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

// the settings of the assistant, for its requests (the key: '' if none)
export const assistantSettings = () => ({provider, model, key});

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
  if(!r.ok) {
    const why = (body && body.error && body.error.message) || r.statusText;
    if(r.status === 401) return {error: `Key refused by ${providers[name].name}: ${why}`};
    return {error: `${providers[name].name} answered ${r.status}: ${why}`};
  }
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
