import json
from pathlib import Path
import tempfile
import unittest

from check_native_outputs import audit, inspect_mesh, read_msh2


def square(height=0., triangle='11 21 31'):
    return f'''$MeshFormat
2.2 0 8
$EndMeshFormat
$Nodes
4
11 0 0 {height}
21 1 0 {height}
31 1 1 {height}
41 0 1 {height}
$EndNodes
$Elements
2
1 2 2 7 7 {triangle}
2 2 2 7 7 11 31 41
$EndElements
$ElementData
1
"MAT parent"
1
0
3
0
1
2
1 0
2 1
$EndElementData
'''


class NativeOutputAuditTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.folder = Path(self.temporary.name)
        for stage in ('skin', 'raw', 'filtered', 'projected', 'extended'):
            (self.folder/(stage+'.msh')).write_text(square())
        self.report = dict(projectionStatus='unchanged', extension=dict(complete=False, fronts=[
            dict(a=a, b=b, branch=6, status='unresolved', reason='test')
            for a, b in [(0, 1), (1, 2), (2, 3), (0, 3)]]))
        self.report['stages'] = {name: dict(vertices=4, triangles=2, components=1,
                                          free_edges=4, junction_edges=0, euler=1)
                                 for name in ('raw', 'filtered', 'projected', 'extended')}
        self.save()

    def save(self):
        (self.folder/'report.json').write_text(json.dumps(self.report))

    def tearDown(self):
        self.temporary.cleanup()

    def test_arbitrary_node_ids_and_complete_front_ledger(self):
        result = audit(self.folder, 'extended')
        self.assertTrue(result['passed'], result['failures'])
        self.assertEqual(result['snapshots']['filtered']['euler'], 1)
        self.assertEqual(result['snapshots']['filtered']['components'], 1)
        self.assertEqual(result['extension']['expected_fronts'], 4)

    def test_missing_triangle_node_is_rejected(self):
        (self.folder/'filtered.msh').write_text(square(triangle='11 21 999'))
        result = audit(self.folder, 'filtered')
        self.assertFalse(result['passed'])
        self.assertIn('missing node', result['failures'][0])

    def test_rejected_projection_must_preserve_coordinates(self):
        (self.folder/'projected.msh').write_text(square(height=.1))
        result = audit(self.folder, 'projected', project=True)
        self.assertFalse(result['passed'])
        self.assertTrue(any('exact input' in reason for reason in result['failures']))

    def test_applied_projection_may_move_but_not_change_triangles(self):
        self.report['projectionStatus'] = 'applied'
        self.save()
        (self.folder/'projected.msh').write_text(square(height=.1))
        self.assertTrue(audit(self.folder, 'projected', project=True)['passed'])
        (self.folder/'projected.msh').write_text(square(height=.1, triangle='21 31 41'))
        result = audit(self.folder, 'projected', project=True)
        self.assertFalse(result['passed'])
        self.assertTrue(any('triangle records' in reason for reason in result['failures']))

    def test_skipped_front_cannot_disappear_from_ledger(self):
        self.report['extension']['fronts'].pop()
        self.save()
        result = audit(self.folder, 'extended')
        self.assertFalse(result['passed'])
        self.assertTrue(any('each input free edge' in reason for reason in result['failures']))

    def test_unresolved_front_cannot_be_called_complete(self):
        self.report['extension']['complete'] = True
        self.save()
        result = audit(self.folder, 'extended')
        self.assertFalse(result['passed'])
        self.assertTrue(any('claims completion' in reason for reason in result['failures']))

    def test_duplicate_triangle_is_rejected(self):
        path = self.folder/'filtered.msh'
        path.write_text(square().replace('7 7 11 31 41', '7 7 31 21 11'))
        with self.assertRaisesRegex(ValueError, 'Duplicate triangle'):
            inspect_mesh(read_msh2(path))

    def test_projection_preserves_parent_lineage(self):
        path = self.folder/'projected.msh'
        path.write_text(square().replace('1 0\n2 1\n', '1 8\n2 1\n'))
        result = audit(self.folder, 'projected')
        self.assertFalse(result['passed'])
        self.assertTrue(any('triangle records' in reason for reason in result['failures']))

    def test_report_cannot_hide_a_different_component_count(self):
        self.report['stages']['filtered']['components'] = 2
        self.save()
        result = audit(self.folder, 'filtered')
        self.assertFalse(result['passed'])
        self.assertTrue(any('reported components' in reason for reason in result['failures']))

    def test_front_branch_must_match_input(self):
        self.report['extension']['fronts'][0]['branch'] = 9
        self.save()
        result = audit(self.folder, 'extended')
        self.assertFalse(result['passed'])
        self.assertTrue(any('Front branch' in reason for reason in result['failures']))


if __name__ == '__main__':
    unittest.main()
